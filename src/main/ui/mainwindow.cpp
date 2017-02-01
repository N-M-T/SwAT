/***************************************************************************
**                                                                        **
**  Sway Analysis Toolkit (SwAT)                                          **
**                                                                        **
**  Copyright (C) 2016-2017 Neil Thomas                                   **
**  All rights reserved.                                                  **
**                                                                        **
**  This file is part of the SwAT.                                        **
**                                                                        **
**  The SwAT is free software: you can redistribute it and/or modify      **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Neil Thomas                                          **
**          Contact: neil.thomas@uni.cumbria.ac.uk                        **
**             Date: 10.01.17                                             **
**          Version: 1.0.0-beta                                           **
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QInputDialog>

#include <QTextStream>

#include <stdio.h>
#include <eigen-eigen-26667be4f70b/Eigen/Dense>

#include <math.h>

#include "main/filters/filterS.h"
#include "main/io/resizing.h"

using namespace std;
using namespace Eigen;

//temp containers

int tempFreq = 0;
int tempLength = 0;
int tempTime = 0;

ArrayXd X;
ArrayXd Y;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //change stretch layout and double slider here
    //so I don't have to keep editing ui_mainwindow.h

    ui->gridLayout->setRowStretch(1,20);

    doubleSlider = new QxtSpanSlider(Qt::Horizontal, this);
    ui->sliderField->insertWidget(0, doubleSlider);

    doubleSlider->setHandleMovementMode(QxtSpanSlider::NoOverlapping);
    doubleSlider->setTickPosition(QxtSpanSlider::TicksBelow);
    doubleSlider->setTickInterval(5);
    doubleSlider->setSingleStep(1);

    //hide slider, spinbox's and filter toolkit until file is loaded

    ui->timeAdjustLabel->hide();
    ui->minSpinBox->hide();
    ui->minSpinBoxSuffix->hide();
    doubleSlider->hide();
    ui->maxSpinBox->hide();
    ui->maxSpinBoxSuffix->hide();
    ui->resultantLabel->hide();
    ui->resultantSpinBoxSuffix->hide();

    ui->detrend->hide();

    ui->filterCombo->hide();
    ui->filterLabel->hide();
    ui->orderCombo->hide();
    ui->orderLabel->hide();
    ui->cuttoffCombo->hide();
    ui->cuttoffLabel->hide();

    //update spinbox from doubleSlider signals and slots

    connect(doubleSlider, SIGNAL(lowerPositionChanged(int)), this, SLOT(setLowerSpinBox(int)));
    connect(doubleSlider, SIGNAL(upperPositionChanged(int)), this, SLOT(setUpperSpinBox(int)));

    //update slider signals and slots

    connect(ui->minSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setSlider(int)));
    connect(ui->maxSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setSlider(int)));

    //update resultant spinbox from spinbox values

    connect(ui->minSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setResultantLabel(int)));
    connect(ui->maxSpinBox, SIGNAL(valueChanged(int)), this, SLOT(setResultantLabel(int)));

    //connect to comboBox
    connect(ui->filterCombo, SIGNAL(currentIndexChanged(QString)), this, SLOT(open_closeFilterOptions(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//open file

void MainWindow::on_actionOpen_Ctrl_O_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"),
                                                    QDir::homePath(),
                                                    tr("Text Files(*.txt)"));

    if (!fileName.isEmpty())
    {
        //convert filename to correct format

        QByteArray ba = fileName.toLatin1();
        const char *c_str2 = ba.data();

        //send filename to parser and receive x and y arrays

        parsed parsedData = parsing(c_str2);

        //error handling

        if (parsedData.X.size() < 1)
        {
            ui->textBrowser2->append("Invalid file");
        }
        else
        {
            //get sampling frequency

            bool ok;

            int freq = QInputDialog::getInt(this, tr("Sampling frequency"),
                                               tr("Enter sampling frequency:"), 100, 10, 2000, 1, &ok);
            if (ok)
            {
                //assign X and Y arrays returned data

                X.resize(0);
                Y.resize(0);

                X = parsedData.X;
                Y = parsedData.Y;

                //assign sampling frequency and length of data

                tempFreq = freq;

                tempLength = X.size();

                //calculate time of trial

                tempTime = tempLength/tempFreq;

                //display raw data in textBrowser

                QFile file(fileName);
                file.open(QIODevice::ReadOnly);

                QTextStream in(&file);
                ui->textBrowser->setText(in.readAll());
                file.close();

                //output file loaded

                ui->textBrowser2->append("File loaded:   " + fileName);

                //set slider variables

                doubleSlider->setMinimum(0);
                doubleSlider->setMaximum(tempTime);
                doubleSlider->setLowerValue(0);
                doubleSlider->setUpperValue(tempTime);
                doubleSlider->setUpperPosition(tempTime);

                ui->minSpinBox->setValue(0);
                ui->minSpinBox->setMaximum(tempTime-1);
                ui->maxSpinBox->setValue(tempTime);
                ui->maxSpinBox->setMinimum(1);
                ui->maxSpinBox->setMaximum(tempTime);

                ui->resultantLabel->setText(QString::number(tempTime));

                //show widgets

                ui->timeAdjustLabel->show();
                ui->minSpinBox->show();
                ui->minSpinBoxSuffix->show();
                doubleSlider->show();
                ui->maxSpinBox->show();
                ui->maxSpinBoxSuffix->show();
                ui->resultantLabel->show();
                ui->resultantSpinBoxSuffix->show();

                ui->detrend->show();

                ui->filterCombo->show();
                ui->filterLabel->show();
             }
             else
             {
                ui->textBrowser2->append("Cancelled");
             }
        }
     }
}

void MainWindow::on_actionBasic_triggered()
{
    if (tempFreq == 0)
        ui->textBrowser2->append("No file loaded");
    else
        openResultsWindow();
}

void MainWindow::setLowerSpinBox(int value)
{
    ui->minSpinBox->setValue(value);
}

void MainWindow::setUpperSpinBox(int value)
{
    ui->maxSpinBox->setValue(value);
}

void MainWindow::setSlider(int value)
{
    if (sender()==ui->minSpinBox)
        doubleSlider->setLowerPosition(value);

    if (sender()==ui->maxSpinBox)
        doubleSlider->setUpperPosition(value);
}

void MainWindow::setResultantLabel(int value)
{
    if (sender()==ui->minSpinBox)
        ui->resultantLabel->setText(QString::number(ui->maxSpinBox->value() - value));

    if (sender()==ui->maxSpinBox)
        ui->resultantLabel->setText(QString::number(value - ui->minSpinBox->value()));
}

void MainWindow::open_closeFilterOptions(QString type)
{
    if (type != QString("No filter"))
    {
        ui->orderCombo->show();
        ui->orderLabel->show();
        ui->cuttoffCombo->show();
        ui->cuttoffLabel->show();
    }
    else
    {
        ui->orderCombo->hide();
        ui->orderLabel->hide();
        ui->cuttoffCombo->hide();
        ui->cuttoffLabel->hide();
    }
}

void MainWindow::openResultsWindow()
{
    //filter raw data if required

    ArrayXd tempX, tempY;
    tempX.resize(0,1);
    tempY.resize(0,1);

    if (ui->filterCombo->currentText() != QString("No filter"))
    {
        int order = ui->orderCombo->currentText().toInt();
        int cuttoff = ui->cuttoffCombo->currentText().toInt();

        filtered filteredData = filtering(X, Y, order, cuttoff, tempFreq);

        tempX = filteredData.tempX;
        tempY = filteredData.tempY;
    }
    else
    {
        tempX = X;
        tempY = Y;
    }

    //resize data arrays to correspond with new length of data from slider

    //get new values

    int minLength = ui->minSpinBox->value() * tempFreq;
    int maxLength = ui->maxSpinBox->value() * tempFreq;

    //send values to resizer function

    newData resized = resizing(tempX, tempY, minLength, maxLength);

    int newLength = maxLength - minLength;

    //assign new arrays

    ArrayXd newX = resized.newX;
    ArrayXd newY = resized.newY;

    //remove mean if detrend box is checked

    if (ui->detrend->isChecked())
    {
        double meanX = newX.mean();
        double meanY = newY.mean();

        newX = newX - meanX;
        newY = newY - meanY;
    }

    analysed analysedData = results(newX, newY, newLength, tempFreq);

    //construct results window and pass results

    mResultsWindow = new resultsWindow;
    mResultsWindow->setData(analysedData.tp, analysedData.avgVel,
                            analysedData.ce, analysedData.sdX,
                            analysedData.sdY, analysedData.rmsX,
                            analysedData.rmsY);

    mResultsWindow->show();
}

void MainWindow::on_actionQuit_Ctrl_Q_triggered()
{
    this->close();
}

void MainWindow::on_actionPlot_triggered()
{
    if (tempFreq == 0)
    {
        ui->textBrowser2->append("No file loaded");
    }
    else
    {
        //filter raw data if required

        ArrayXd tempX, tempY;
        tempX.resize(0,1);
        tempY.resize(0,1);

        if (ui->filterCombo->currentText() != QString("No filter"))
        {
            int order = ui->orderCombo->currentText().toInt();
            int cuttoff = ui->cuttoffCombo->currentText().toInt();

            filtered filteredData = filtering(X, Y, order, cuttoff, tempFreq);

            tempX = filteredData.tempX;
            tempY = filteredData.tempY;
        }
        else
        {
            tempX = X;
            tempY = Y;
        }

        //resize data arrays to correspond with new length of data from slider

        //get new values

        int minLength = ui->minSpinBox->value() * tempFreq;
        int maxLength = ui->maxSpinBox->value() * tempFreq;

        //send values to resizer function

        newData resized = resizing(tempX, tempY, minLength, maxLength);

        //assign new arrays

        ArrayXd newX = resized.newX;
        ArrayXd newY = resized.newY;

        //remove mean if detrend box is checked

        if (ui->detrend->isChecked())
        {
            double meanX = newX.mean();
            double meanY = newY.mean();

            newX = newX - meanX;
            newY = newY - meanY;
        }

        mPlotting = new plotting;

        mPlotting->setData(newX, newY, tempFreq);
        mPlotting->show();
    }
}
