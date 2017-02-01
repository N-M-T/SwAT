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

#include "plotting.h"
#include "main/ui/ui_plotting.h"
//#include "qcustomplot.h"

plotting::plotting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plotting)
{
    ui->setupUi(this);
}

plotting::~plotting()
{
    delete ui;
}

void plotting::setData(ArrayXd X, ArrayXd Y, int tempFreq)
{
    //determine length of data

    int length = X.size();

    //min and max values for axis scaling

    double xMin = X.minCoeff();
    double xMax = X.maxCoeff();

    double yMin = Y.minCoeff();
    double yMax = Y.maxCoeff();

    //make vectors for x axis (time) and for x Eigen array

    QVector<double> x_forAxis(length), x_forData(length);

    for (double a = 0; a < length; a++)
    {
        x_forAxis[a] = a / tempFreq;
        x_forData[a] = X(a);
    }

    // create graph for medial/lateral axis and assign data to it:

    ui->ml->addGraph();
    ui->ml->graph()->setData(x_forAxis, x_forData);

    ui->ml->xAxis->setLabel("time (s)");
    ui->ml->yAxis->setLabel("Displacement (cm)");

    ui->ml->xAxis->setRange(0, length / tempFreq);
    ui->ml->yAxis->setRange(xMin, xMax);
    ui->ml->replot();

    //add title

    ui->ml->plotLayout()->insertRow(0);
    ui->ml->plotLayout()->addElement(0, 0, new QCPTextElement(ui->ml, "Medial/lateral axis", QFont("sans", 12, QFont::Bold)));

    //make plot interactive

    ui->ml->setInteraction(QCP::iRangeDrag, true);
    ui->ml->setInteraction(QCP::iRangeZoom, true);

    //plot anterior/posterior

    QVector<double> y_forData(length);

    for (int b = 0; b < length; b++)
        y_forData[b] = Y(b);

    ui->ap->addGraph();
    ui->ap->graph()->setData(x_forAxis, y_forData);

    ui->ap->xAxis->setLabel("time (s)");
    ui->ap->yAxis->setLabel("Displacement (cm)");

    ui->ap->xAxis->setRange(0, length / tempFreq);
    ui->ap->yAxis->setRange(yMin, yMax);
    ui->ap->replot();

    ui->ap->plotLayout()->insertRow(0);
    ui->ap->plotLayout()->addElement(0, 0, new QCPTextElement(ui->ap, "Anterior/posterior axis", QFont("sans", 12, QFont::Bold)));

    ui->ap->setInteraction(QCP::iRangeDrag, true);
    ui->ap->setInteraction(QCP::iRangeZoom, true);

    //plot resultant direction

    QCPCurve *newCurve = new QCPCurve(ui->rd->xAxis, ui->rd->yAxis);

    newCurve->setName("Resultant direction");
    newCurve->setData(x_forAxis, x_forData, y_forData);

    ui->rd->xAxis->setLabel("Medial/lateral (cm)");
    ui->rd->yAxis->setLabel("Anterior/posterior (cm)");

    ui->rd->xAxis->setRange(xMin, xMax);
    ui->rd->yAxis->setRange(yMin, yMax);

    ui->rd->replot();

    ui->rd->plotLayout()->insertRow(0);
    ui->rd->plotLayout()->addElement(0, 0, new QCPTextElement(ui->rd, "Resultant direction", QFont("sans", 12, QFont::Bold)));

    ui->rd->setInteraction(QCP::iRangeDrag, true);
    ui->rd->setInteraction(QCP::iRangeZoom, true);
}


void plotting::on_save_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save plots"), "",
                                                          tr("Image files (*.jpg)"));

    if (!filename.isEmpty())
    {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly))
        {
            //textBrowser->setText("Cancelled");
        }
        else
        {
            ui->ml->saveJpg(filename + "_" + "medial_lateral", 0, 0, 1.0, -1);
            ui->ap->saveJpg(filename + "_" + "anterior_posterior", 0, 0, 1.0, -1);
            ui->rd->saveJpg(filename + "_" + "resultant_direction", 0, 0, 1.0, -1);
        }

        file.close();
        close();
     }
}

void plotting::on_cancel_clicked()
{
    close();
}
