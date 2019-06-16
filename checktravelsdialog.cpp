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
    table->setColumnCount(4);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Travel"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("Roundtrip?"));

    // Tabelle leeren
    table->clear();
    table->setRowCount(agency->getNumberOfTravels());

    // Tabelle füllen
    for (int row=0; row<agency->getNumberOfTravels(); row++) {
        table->setItem(row, 0, new QTableWidgetItem(tr("%1").arg(
                                                        agency->getTravelByNo(row)->getId())));
        table->setItem(row, 1, new QTableWidgetItem(tr("%1").arg(
                                                        agency->getTravelByNo(row)->checkRoundTrip())));
        table->setItem(row, 2, new QTableWidgetItem(tr("%1").arg(
                                                        agency->getTravelByNo(row)->checkMissingHotel())));
        table->setItem(row, 3, new QTableWidgetItem(tr("%1").arg(
                                                        agency->getBookingByNo(row)->getTravelId())));
    }
}

CheckTravelsDialog::~CheckTravelsDialog()
{
    delete ui;
}
