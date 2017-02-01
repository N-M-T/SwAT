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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include "main/ui/resultswindow.h"
#include "main/plotting/plotting.h"
#include "main/io/parser.h"
#include "main/analysis/basicanalysis.h"

#include <eigen-eigen-26667be4f70b/Eigen/Dense>
#include "external/qxtSlider/qxtspanslider.h"

using namespace Eigen;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QxtSpanSlider *doubleSlider;

    resultsWindow *mResultsWindow;

    plotting *mPlotting;

private slots:
    void on_actionOpen_Ctrl_O_triggered();

    void on_actionQuit_Ctrl_Q_triggered();

    void on_actionBasic_triggered();

    void on_actionPlot_triggered();

public slots:
    void setLowerSpinBox(int value);

    void setUpperSpinBox(int value);

    void setSlider(int value);

    void setResultantLabel(int value);

    void open_closeFilterOptions(QString type);

    void openResultsWindow();

signals:
    void valueChanged(int value);

    void lowerPositionChanged(int value);

    void upperPositionChanged(int value);

};

#endif // MAINWINDOW_H
