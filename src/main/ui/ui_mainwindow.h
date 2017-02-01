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

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Ctrl_O;
    QAction *actionClose_Ctrl_Q;
    QAction *actionBasic;
    QAction *actionPlot;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *filterLabel;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *orderCombo;
    QComboBox *cuttoffCombo;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *detrend;
    QComboBox *filterCombo;
    QHBoxLayout *horizontalLayout;
    QSpinBox *minSpinBox;
    QLabel *minSpinBoxSuffix;
    QHBoxLayout *sliderField;
    QSpinBox *maxSpinBox;
    QLabel *maxSpinBoxSuffix;
    QLabel *resultantLabel;
    QLabel *resultantSpinBoxSuffix;
    QVBoxLayout *verticalLayout;
    QLabel *rawDataViewerLabel;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_4;
    QLabel *orderLabel;
    QLabel *cuttoffLabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *outputLabel;
    QTextBrowser *textBrowser2;
    QLabel *timeAdjustLabel;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAnalyse;
    QMenu *menuPlotting;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(451, 446);
        QIcon icon;
        icon.addFile(QStringLiteral("gibbon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen_Ctrl_O = new QAction(MainWindow);
        actionOpen_Ctrl_O->setObjectName(QStringLiteral("actionOpen_Ctrl_O"));
        actionClose_Ctrl_Q = new QAction(MainWindow);
        actionClose_Ctrl_Q->setObjectName(QStringLiteral("actionClose_Ctrl_Q"));
        actionBasic = new QAction(MainWindow);
        actionBasic->setObjectName(QStringLiteral("actionBasic"));
        actionPlot = new QAction(MainWindow);
        actionPlot->setObjectName(QStringLiteral("actionPlot"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filterLabel = new QLabel(centralwidget);
        filterLabel->setObjectName(QStringLiteral("filterLabel"));

        horizontalLayout_2->addWidget(filterLabel);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        orderCombo = new QComboBox(centralwidget);
        orderCombo->setObjectName(QStringLiteral("orderCombo"));

        horizontalLayout_5->addWidget(orderCombo);

        cuttoffCombo = new QComboBox(centralwidget);
        cuttoffCombo->setObjectName(QStringLiteral("cuttoffCombo"));

        horizontalLayout_5->addWidget(cuttoffCombo);


        gridLayout->addLayout(horizontalLayout_5, 4, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        detrend = new QCheckBox(centralwidget);
        detrend->setObjectName(QStringLiteral("detrend"));

        horizontalLayout_3->addWidget(detrend);

        filterCombo = new QComboBox(centralwidget);
        filterCombo->setObjectName(QStringLiteral("filterCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(20);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filterCombo->sizePolicy().hasHeightForWidth());
        filterCombo->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(filterCombo);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        minSpinBox = new QSpinBox(centralwidget);
        minSpinBox->setObjectName(QStringLiteral("minSpinBox"));

        horizontalLayout->addWidget(minSpinBox);

        minSpinBoxSuffix = new QLabel(centralwidget);
        minSpinBoxSuffix->setObjectName(QStringLiteral("minSpinBoxSuffix"));

        horizontalLayout->addWidget(minSpinBoxSuffix);

        sliderField = new QHBoxLayout();
        sliderField->setObjectName(QStringLiteral("sliderField"));

        horizontalLayout->addLayout(sliderField);

        maxSpinBox = new QSpinBox(centralwidget);
        maxSpinBox->setObjectName(QStringLiteral("maxSpinBox"));

        horizontalLayout->addWidget(maxSpinBox);

        maxSpinBoxSuffix = new QLabel(centralwidget);
        maxSpinBoxSuffix->setObjectName(QStringLiteral("maxSpinBoxSuffix"));

        horizontalLayout->addWidget(maxSpinBoxSuffix);

        resultantLabel = new QLabel(centralwidget);
        resultantLabel->setObjectName(QStringLiteral("resultantLabel"));

        horizontalLayout->addWidget(resultantLabel);

        resultantSpinBoxSuffix = new QLabel(centralwidget);
        resultantSpinBoxSuffix->setObjectName(QStringLiteral("resultantSpinBoxSuffix"));

        horizontalLayout->addWidget(resultantSpinBoxSuffix);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rawDataViewerLabel = new QLabel(centralwidget);
        rawDataViewerLabel->setObjectName(QStringLiteral("rawDataViewerLabel"));

        verticalLayout->addWidget(rawDataViewerLabel);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        orderLabel = new QLabel(centralwidget);
        orderLabel->setObjectName(QStringLiteral("orderLabel"));

        horizontalLayout_4->addWidget(orderLabel);

        cuttoffLabel = new QLabel(centralwidget);
        cuttoffLabel->setObjectName(QStringLiteral("cuttoffLabel"));

        horizontalLayout_4->addWidget(cuttoffLabel);


        gridLayout->addLayout(horizontalLayout_4, 3, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        outputLabel = new QLabel(centralwidget);
        outputLabel->setObjectName(QStringLiteral("outputLabel"));

        verticalLayout_2->addWidget(outputLabel);

        textBrowser2 = new QTextBrowser(centralwidget);
        textBrowser2->setObjectName(QStringLiteral("textBrowser2"));

        verticalLayout_2->addWidget(textBrowser2);

        timeAdjustLabel = new QLabel(centralwidget);
        timeAdjustLabel->setObjectName(QStringLiteral("timeAdjustLabel"));

        verticalLayout_2->addWidget(timeAdjustLabel);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 451, 19));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAnalyse = new QMenu(menubar);
        menuAnalyse->setObjectName(QStringLiteral("menuAnalyse"));
        menuPlotting = new QMenu(menubar);
        menuPlotting->setObjectName(QStringLiteral("menuPlotting"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAnalyse->menuAction());
        menubar->addAction(menuPlotting->menuAction());
        menuFile->addAction(actionOpen_Ctrl_O);
        menuFile->addAction(actionClose_Ctrl_Q);
        menuAnalyse->addAction(actionBasic);
        menuPlotting->addAction(actionPlot);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sway analysis toolkit (SwAT)", 0));
        actionOpen_Ctrl_O->setText(QApplication::translate("MainWindow", "Open   ", 0));
        actionOpen_Ctrl_O->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionClose_Ctrl_Q->setText(QApplication::translate("MainWindow", "Close   ", 0));
        actionClose_Ctrl_Q->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionBasic->setText(QApplication::translate("MainWindow", "Basic", 0));
        actionPlot->setText(QApplication::translate("MainWindow", "Plot builder", 0));
        filterLabel->setText(QApplication::translate("MainWindow", "Filtering", 0));
        orderCombo->clear();
        orderCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "4", 0)
         << QApplication::translate("MainWindow", "6", 0)
        );
        cuttoffCombo->clear();
        cuttoffCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "4", 0)
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
         << QApplication::translate("MainWindow", "9", 0)
         << QApplication::translate("MainWindow", "10", 0)
         << QApplication::translate("MainWindow", "11", 0)
         << QApplication::translate("MainWindow", "12", 0)
         << QApplication::translate("MainWindow", "13", 0)
         << QApplication::translate("MainWindow", "14", 0)
         << QApplication::translate("MainWindow", "15", 0)
         << QApplication::translate("MainWindow", "16", 0)
         << QApplication::translate("MainWindow", "17", 0)
         << QApplication::translate("MainWindow", "18", 0)
         << QApplication::translate("MainWindow", "19", 0)
         << QApplication::translate("MainWindow", "20", 0)
         << QApplication::translate("MainWindow", "21", 0)
         << QApplication::translate("MainWindow", "22", 0)
         << QApplication::translate("MainWindow", "23", 0)
         << QApplication::translate("MainWindow", "24", 0)
         << QApplication::translate("MainWindow", "25", 0)
         << QApplication::translate("MainWindow", "26", 0)
         << QApplication::translate("MainWindow", "27", 0)
         << QApplication::translate("MainWindow", "28", 0)
         << QApplication::translate("MainWindow", "29", 0)
         << QApplication::translate("MainWindow", "30", 0)
        );
        detrend->setText(QApplication::translate("MainWindow", "Detrend", 0));
        filterCombo->clear();
        filterCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "No filter", 0)
         << QApplication::translate("MainWindow", "Butterworth filter", 0)
        );
        minSpinBoxSuffix->setText(QApplication::translate("MainWindow", "s", 0));
        maxSpinBoxSuffix->setText(QApplication::translate("MainWindow", "s", 0));
        resultantLabel->setText(QString());
        resultantSpinBoxSuffix->setText(QApplication::translate("MainWindow", "s", 0));
        rawDataViewerLabel->setText(QApplication::translate("MainWindow", "Raw data viewer", 0));
        orderLabel->setText(QApplication::translate("MainWindow", "Order", 0));
        cuttoffLabel->setText(QApplication::translate("MainWindow", "Cuttoff (Hz)", 0));
        outputLabel->setText(QApplication::translate("MainWindow", "Output", 0));
        timeAdjustLabel->setText(QApplication::translate("MainWindow", "Time adjust", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuAnalyse->setTitle(QApplication::translate("MainWindow", "Analyse", 0));
        menuPlotting->setTitle(QApplication::translate("MainWindow", "Plot", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
