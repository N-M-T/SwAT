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

#include "resultswindow.h"
#include "ui_resultswindow.h"
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QFileDialog>

resultsWindow::resultsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::resultsWindow)
{
    ui->setupUi(this);
}

resultsWindow::~resultsWindow()
{
    delete ui;
}

void resultsWindow::setData(double tp, double avgVel, double ce, double sdX, double sdY, double rmsX, double rmsY)
{
     ui->tableWidget->setItem(0,0, new QTableWidgetItem(QString::number(tp, 'f', 3)));
     ui->tableWidget->setItem(0,1, new QTableWidgetItem(QString::number(avgVel, 'f', 3)));
     ui->tableWidget->setItem(0,2, new QTableWidgetItem(QString::number(ce, 'f', 3)));
     ui->tableWidget->setItem(0,3, new QTableWidgetItem(QString::number(sdX, 'f', 3)));
     ui->tableWidget->setItem(0,4, new QTableWidgetItem(QString::number(sdY, 'f', 3)));
     ui->tableWidget->setItem(0,5, new QTableWidgetItem(QString::number(rmsX, 'f', 3)));
     ui->tableWidget->setItem(0,6, new QTableWidgetItem(QString::number(rmsY, 'f', 3)));
}

void resultsWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save results"), "",
                                                          tr("Text files (*.txt)"));

    if (!filename.isEmpty())
    {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly))
        {
            //textBrowser->setText("Cancelled");
        }
        else
        {
            QTextStream data(&file);
            QStringList strList;

            int rows = ui->tableWidget->rowCount();

            for (int row = 1; row < rows; row++)
            {
                strList.clear();

                QTableWidgetItem* item = ui->tableWidget->item(row, 0);

                if (!item || item->text().isEmpty())
                {
                    ui->tableWidget->setItem(row, 0, new QTableWidgetItem("No result"));
                }

                strList << "\"" + ui->tableWidget->verticalHeaderItem(row)-> data(Qt::DisplayRole).toString() + "   "
                                + ui->tableWidget->item(row, 0)->text() + "\"";

                data << strList.join( ";" ) + "\n";
            }

            file.close();

            close();

            //return true;

        }
    }
}

void resultsWindow::on_pushButton_2_clicked()
{
    close();
}
