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

QT_BEGIN_NAMESPACE

class Ui_CheckTravelsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *CheckTravelsDialog)
    {
        if (CheckTravelsDialog->objectName().isEmpty())
            CheckTravelsDialog->setObjectName(QString::fromUtf8("CheckTravelsDialog"));
        CheckTravelsDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(CheckTravelsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(CheckTravelsDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(25, 21, 351, 221));

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
