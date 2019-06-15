/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEinlesen;
    QAction *actionEinlesen_2;
    QAction *actionProgramm_beenden;
    QAction *actionNeue_Buchung_anlegen;
    QAction *actionSpeichern_unter;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_V;
    QGridLayout *gridLayout_5;
    QLabel *label_V3;
    QLabel *label_V1;
    QLabel *label_V2;
    QLineEdit *lineEdit_V2;
    QLineEdit *lineEdit_V3;
    QLineEdit *lineEdit_V1;
    QFormLayout *formLayout;
    QLabel *label_2;
    QCalendarWidget *calendarWidget;
    QLabel *label_3;
    QCalendarWidget *calendarWidget_2;
    QLabel *label_7;
    QLineEdit *lineEdit_Preis;
    QLabel *label_8;
    QLineEdit *lineEdit_Reise;
    QLabel *label_9;
    QLineEdit *lineEdit_Kunde;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *labelBuchungsnummer;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuDatei;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 700);
        actionEinlesen = new QAction(MainWindow);
        actionEinlesen->setObjectName(QString::fromUtf8("actionEinlesen"));
        actionEinlesen_2 = new QAction(MainWindow);
        actionEinlesen_2->setObjectName(QString::fromUtf8("actionEinlesen_2"));
        actionProgramm_beenden = new QAction(MainWindow);
        actionProgramm_beenden->setObjectName(QString::fromUtf8("actionProgramm_beenden"));
        actionNeue_Buchung_anlegen = new QAction(MainWindow);
        actionNeue_Buchung_anlegen->setObjectName(QString::fromUtf8("actionNeue_Buchung_anlegen"));
        actionSpeichern_unter = new QAction(MainWindow);
        actionSpeichern_unter->setObjectName(QString::fromUtf8("actionSpeichern_unter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(300, 100));
        tableWidget->setMaximumSize(QSize(650, 16777215));

        gridLayout_4->addWidget(tableWidget, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(400, 16777215));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_V = new QGroupBox(groupBox);
        groupBox_V->setObjectName(QString::fromUtf8("groupBox_V"));
        gridLayout_5 = new QGridLayout(groupBox_V);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_V3 = new QLabel(groupBox_V);
        label_V3->setObjectName(QString::fromUtf8("label_V3"));

        gridLayout_5->addWidget(label_V3, 2, 0, 1, 1);

        label_V1 = new QLabel(groupBox_V);
        label_V1->setObjectName(QString::fromUtf8("label_V1"));

        gridLayout_5->addWidget(label_V1, 0, 0, 1, 1);

        label_V2 = new QLabel(groupBox_V);
        label_V2->setObjectName(QString::fromUtf8("label_V2"));

        gridLayout_5->addWidget(label_V2, 1, 0, 1, 1);

        lineEdit_V2 = new QLineEdit(groupBox_V);
        lineEdit_V2->setObjectName(QString::fromUtf8("lineEdit_V2"));

        gridLayout_5->addWidget(lineEdit_V2, 1, 1, 1, 1);

        lineEdit_V3 = new QLineEdit(groupBox_V);
        lineEdit_V3->setObjectName(QString::fromUtf8("lineEdit_V3"));

        gridLayout_5->addWidget(lineEdit_V3, 2, 1, 1, 1);

        lineEdit_V1 = new QLineEdit(groupBox_V);
        lineEdit_V1->setObjectName(QString::fromUtf8("lineEdit_V1"));

        gridLayout_5->addWidget(lineEdit_V1, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_V, 4, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        calendarWidget = new QCalendarWidget(groupBox);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        formLayout->setWidget(1, QFormLayout::FieldRole, calendarWidget);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        calendarWidget_2 = new QCalendarWidget(groupBox);
        calendarWidget_2->setObjectName(QString::fromUtf8("calendarWidget_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, calendarWidget_2);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        lineEdit_Preis = new QLineEdit(groupBox);
        lineEdit_Preis->setObjectName(QString::fromUtf8("lineEdit_Preis"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_Preis);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        lineEdit_Reise = new QLineEdit(groupBox);
        lineEdit_Reise->setObjectName(QString::fromUtf8("lineEdit_Reise"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_Reise);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_9);

        lineEdit_Kunde = new QLineEdit(groupBox);
        lineEdit_Kunde->setObjectName(QString::fromUtf8("lineEdit_Kunde"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_Kunde);


        gridLayout_2->addLayout(formLayout, 3, 0, 1, 1);

        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 2, 2);

        labelBuchungsnummer = new QLabel(frame_2);
        labelBuchungsnummer->setObjectName(QString::fromUtf8("labelBuchungsnummer"));

        gridLayout_3->addWidget(labelBuchungsnummer, 1, 1, 1, 1);


        gridLayout_2->addWidget(frame_2, 2, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuDatei->menuAction());
        menuDatei->addAction(actionEinlesen_2);
        menuDatei->addAction(actionNeue_Buchung_anlegen);
        menuDatei->addAction(actionSpeichern_unter);
        menuDatei->addSeparator();
        menuDatei->addAction(actionProgramm_beenden);

        retranslateUi(MainWindow);
        QObject::connect(tableWidget, SIGNAL(cellDoubleClicked(int,int)), MainWindow, SLOT(detailsAnzeigen()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionEinlesen->setText(QApplication::translate("MainWindow", "Einlesen", nullptr));
        actionEinlesen_2->setText(QApplication::translate("MainWindow", "Einlesen", nullptr));
        actionProgramm_beenden->setText(QApplication::translate("MainWindow", "Programm beenden", nullptr));
        actionNeue_Buchung_anlegen->setText(QApplication::translate("MainWindow", "Neue Buchung anlegen", nullptr));
        actionSpeichern_unter->setText(QApplication::translate("MainWindow", "Speichern unter...", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Buchungsdetails", nullptr));
        groupBox_V->setTitle(QApplication::translate("MainWindow", "Flugdetails", nullptr));
        label_V3->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_V1->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_V2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>von:</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "bis:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Preis:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Reise:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Kunde:", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Buchungsnummer: </p></body></html>", nullptr));
        labelBuchungsnummer->setText(QApplication::translate("MainWindow", "?", nullptr));
        menuDatei->setTitle(QApplication::translate("MainWindow", "Datei", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
