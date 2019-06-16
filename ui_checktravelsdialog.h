/********************************************************************************
** Form generated from reading UI file 'checktravelsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKTRAVELSDIALOG_H
#define UI_CHECKTRAVELSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CheckTravelsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CheckTravelsDialog)
    {
        if (CheckTravelsDialog->objectName().isEmpty())
            CheckTravelsDialog->setObjectName(QString::fromUtf8("CheckTravelsDialog"));
        CheckTravelsDialog->resize(400, 430);
        verticalLayout = new QVBoxLayout(CheckTravelsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(CheckTravelsDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout->addWidget(tableWidget);

        buttonBox = new QDialogButtonBox(CheckTravelsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CheckTravelsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CheckTravelsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CheckTravelsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CheckTravelsDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckTravelsDialog)
    {
        CheckTravelsDialog->setWindowTitle(QApplication::translate("CheckTravelsDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckTravelsDialog: public Ui_CheckTravelsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKTRAVELSDIALOG_H
