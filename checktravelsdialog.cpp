#include "checktravelsdialog.h"
#include "ui_checktravelsdialog.h"

CheckTravelsDialog::CheckTravelsDialog(QWidget *parent, TravelAgency* agency) :
    QDialog(parent),
    ui(new Ui::CheckTravelsDialog),
    agency(agency)
{
    ui->setupUi(this);

    // Tabelle init
    QTableWidget* table = this->ui->tableWidget;
    table->setRowCount(0);
    table->setColumnCount(5);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // Tabelle leeren
    table->clear();
    table->setRowCount(agency->getNumberOfTravels());

    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Travel"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Roundtrip?"));
    table->setHorizontalHeaderItem(2, new QTableWidgetItem("Lückenlos?"));
    table->setHorizontalHeaderItem(3, new QTableWidgetItem("Unnötiges Hotel?"));
    table->setHorizontalHeaderItem(4, new QTableWidgetItem("Unnötiges Auto?"));

    const QString STR_OK = "OK";
    const QString STR_ERR = "Fehler!";
    QString ergstring = "upsi";

    // Tabelle füllen
    for (int row=0; row<agency->getNumberOfTravels(); row++) {

        // TravelId
        table->setItem(row, 0, new QTableWidgetItem(tr("%1").arg(agency->getTravelByNo(row)->getId())));

        // Roundtrip?
        if (agency->getTravelByNo(row)->checkRoundTrip())
            ergstring = STR_OK;
        else {
            ergstring = STR_ERR;
        }
        table->setItem(row, 1, new QTableWidgetItem(tr("%1").arg(ergstring)));

        // Lückenlos?
        if (agency->getTravelByNo(row)->checkMissingHotel())
            ergstring = STR_OK;
        else {
            ergstring = STR_ERR;
        }
        table->setItem(row, 2, new QTableWidgetItem(tr("%1").arg(ergstring)));

        // Unnötiges Hotel?
        if (agency->getTravelByNo(row)->checkNeedlessHotel())
            ergstring = STR_OK;
        else {
            ergstring = STR_ERR;
        }
        table->setItem(row, 3, new QTableWidgetItem(tr("%1").arg(ergstring)));

        // Unnötiges Auto?
        if (agency->getTravelByNo(row)->checkNeedlessRentalCar())
            ergstring = STR_OK;
        else {
            ergstring = STR_ERR;
        }
        table->setItem(row, 4, new QTableWidgetItem(tr("%1").arg(ergstring)));
    }
}

CheckTravelsDialog::~CheckTravelsDialog()
{
    delete ui;
}
