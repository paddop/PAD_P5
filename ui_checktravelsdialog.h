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
<<<<<<< HEAD
=======
#include <QtWidgets/QVBoxLayout>
>>>>>>> d661366f7d1f691bd1d3412cc3ac72923cbe0871

QT_BEGIN_NAMESPACE

class Ui_CheckTravelsDialog
{
public:
<<<<<<< HEAD
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
=======
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QDialogButtonBox *buttonBox;
>>>>>>> d661366f7d1f691bd1d3412cc3ac72923cbe0871

    void setupUi(QDialog *CheckTravelsDialog)
    {
        if (CheckTravelsDialog->objectName().isEmpty())
            CheckTravelsDialog->setObjectName(QString::fromUtf8("CheckTravelsDialog"));
        CheckTravelsDialog->resize(400, 430);
<<<<<<< HEAD
        buttonBox = new QDialogButtonBox(CheckTravelsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 401, 341, 21));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(CheckTravelsDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(25, 21, 351, 371));
=======
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

>>>>>>> d661366f7d1f691bd1d3412cc3ac72923cbe0871

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
