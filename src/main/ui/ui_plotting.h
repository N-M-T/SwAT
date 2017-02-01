/********************************************************************************
** Form generated from reading UI file 'plotting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTING_H
#define UI_PLOTTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "external/qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_plotting
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *ap;
    QPushButton *save;
    QCustomPlot *ml;
    QCustomPlot *rd;
    QPushButton *cancel;

    void setupUi(QWidget *plotting)
    {
        if (plotting->objectName().isEmpty())
            plotting->setObjectName(QStringLiteral("plotting"));
        plotting->resize(1063, 490);
        gridLayout = new QGridLayout(plotting);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ap = new QCustomPlot(plotting);
        ap->setObjectName(QStringLiteral("ap"));

        gridLayout->addWidget(ap, 1, 0, 1, 1);

        save = new QPushButton(plotting);
        save->setObjectName(QStringLiteral("save"));

        gridLayout->addWidget(save, 2, 1, 1, 1);

        ml = new QCustomPlot(plotting);
        ml->setObjectName(QStringLiteral("ml"));
        ap->raise();

        gridLayout->addWidget(ml, 0, 0, 1, 1);

        rd = new QCustomPlot(plotting);
        rd->setObjectName(QStringLiteral("rd"));
        ml->raise();
        ap->raise();

        gridLayout->addWidget(rd, 0, 1, 2, 1);

        cancel = new QPushButton(plotting);
        cancel->setObjectName(QStringLiteral("cancel"));

        gridLayout->addWidget(cancel, 2, 0, 1, 1);


        retranslateUi(plotting);

        QMetaObject::connectSlotsByName(plotting);
    } // setupUi

    void retranslateUi(QWidget *plotting)
    {
        plotting->setWindowTitle(QApplication::translate("plotting", "Plot builder", 0));
        save->setText(QApplication::translate("plotting", "Save", 0));
        cancel->setText(QApplication::translate("plotting", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class plotting: public Ui_plotting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTING_H
