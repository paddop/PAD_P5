/********************************************************************************
** Form generated from reading UI file 'bookingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINGDIALOG_H
#define UI_BOOKINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_BookingDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *preisInput;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLineEdit *travelIDInput;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDateEdit *dateEdit1;
    QDateEdit *dateEdit2;
    QComboBox *comboBox;
    QLabel *label_var1;
    QLabel *label_var2;
    QLabel *label_var3;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QCheckBox *smokeInput;
    QComboBox *seatPrefInput;
    QLabel *label_var4;
    QLineEdit *insuranceInput;

    void setupUi(QDialog *BookingDialog)
    {
        if (BookingDialog->objectName().isEmpty())
            BookingDialog->setObjectName(QString::fromUtf8("BookingDialog"));
        BookingDialog->resize(400, 300);
        BookingDialog->setModal(true);
        formLayout = new QFormLayout(BookingDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(BookingDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        preisInput = new QLineEdit(BookingDialog);
        preisInput->setObjectName(QString::fromUtf8("preisInput"));

        formLayout->setWidget(0, QFormLayout::FieldRole, preisInput);

        buttonBox = new QDialogButtonBox(BookingDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(16, QFormLayout::SpanningRole, buttonBox);

        label_2 = new QLabel(BookingDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        travelIDInput = new QLineEdit(BookingDialog);
        travelIDInput->setObjectName(QString::fromUtf8("travelIDInput"));

        formLayout->setWidget(1, QFormLayout::FieldRole, travelIDInput);

        label_3 = new QLabel(BookingDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(BookingDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(BookingDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        dateEdit1 = new QDateEdit(BookingDialog);
        dateEdit1->setObjectName(QString::fromUtf8("dateEdit1"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dateEdit1);

        dateEdit2 = new QDateEdit(BookingDialog);
        dateEdit2->setObjectName(QString::fromUtf8("dateEdit2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit2);

        comboBox = new QComboBox(BookingDialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox);

        label_var1 = new QLabel(BookingDialog);
        label_var1->setObjectName(QString::fromUtf8("label_var1"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_var1);

        label_var2 = new QLabel(BookingDialog);
        label_var2->setObjectName(QString::fromUtf8("label_var2"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_var2);

        label_var3 = new QLabel(BookingDialog);
        label_var3->setObjectName(QString::fromUtf8("label_var3"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_var3);

        lineEdit_1 = new QLineEdit(BookingDialog);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_1);

        lineEdit_2 = new QLineEdit(BookingDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_2);

        lineEdit_3 = new QLineEdit(BookingDialog);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit_3);

        smokeInput = new QCheckBox(BookingDialog);
        smokeInput->setObjectName(QString::fromUtf8("smokeInput"));

        formLayout->setWidget(12, QFormLayout::FieldRole, smokeInput);

        seatPrefInput = new QComboBox(BookingDialog);
        seatPrefInput->addItem(QString());
        seatPrefInput->addItem(QString());
        seatPrefInput->addItem(QString());
        seatPrefInput->setObjectName(QString::fromUtf8("seatPrefInput"));

        formLayout->setWidget(11, QFormLayout::FieldRole, seatPrefInput);

        label_var4 = new QLabel(BookingDialog);
        label_var4->setObjectName(QString::fromUtf8("label_var4"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_var4);

        insuranceInput = new QLineEdit(BookingDialog);
        insuranceInput->setObjectName(QString::fromUtf8("insuranceInput"));

        formLayout->setWidget(13, QFormLayout::FieldRole, insuranceInput);


        retranslateUi(BookingDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BookingDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BookingDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BookingDialog);
    } // setupUi

    void retranslateUi(QDialog *BookingDialog)
    {
        BookingDialog->setWindowTitle(QApplication::translate("BookingDialog", "Neue Buchung anlegen", nullptr));
        label->setText(QApplication::translate("BookingDialog", "<html><head/><body><p>Preis</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("BookingDialog", "<html><head/><body><p>Travel ID</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("BookingDialog", "<html><head/><body><p>Von</p></body></html>", nullptr));
        label_4->setText(QApplication::translate("BookingDialog", "bis", nullptr));
        label_5->setText(QApplication::translate("BookingDialog", "Typ", nullptr));
        comboBox->setItemText(0, QApplication::translate("BookingDialog", "Flugbuchung", nullptr));
        comboBox->setItemText(1, QApplication::translate("BookingDialog", "Hotelbuchung", nullptr));
        comboBox->setItemText(2, QApplication::translate("BookingDialog", "Mietwagenreservierung", nullptr));

        label_var1->setText(QApplication::translate("BookingDialog", "TextLabel", nullptr));
        label_var2->setText(QApplication::translate("BookingDialog", "TextLabel", nullptr));
        label_var3->setText(QApplication::translate("BookingDialog", "TextLabel", nullptr));
        smokeInput->setText(QApplication::translate("BookingDialog", "Raucher", nullptr));
        seatPrefInput->setItemText(0, QApplication::translate("BookingDialog", "Fenster", nullptr));
        seatPrefInput->setItemText(1, QApplication::translate("BookingDialog", "Gang", nullptr));
        seatPrefInput->setItemText(2, QApplication::translate("BookingDialog", "Egal", nullptr));

        label_var4->setText(QApplication::translate("BookingDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookingDialog: public Ui_BookingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINGDIALOG_H
