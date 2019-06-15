#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "travelagency.h"
#include <QTableWidget>
#include "bookingdialog.h"
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <QFileDialog>
#include <fstream>
#include "checktravelsdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    agency = new TravelAgency();
    QTableWidget* table = this->ui->tableWidget;

    table->setRowCount(0);
    table->setColumnCount(4);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    table->setHorizontalHeaderItem(0, new QTableWidgetItem("Buchungsnummer"));

    ui->groupBox->setHidden(true);

    fillTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::adjustTableSize()
{
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();

    QRect rect = ui->tableWidget->geometry();
    int tableWidth = 2 + ui->tableWidget->verticalHeader()->width();
    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        tableWidth += ui->tableWidget->columnWidth(i);
    }
    rect.setWidth(tableWidth);
    int tableHeight = 2 + ui->tableWidget->horizontalHeader()->height();
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        tableHeight += ui->tableWidget->rowHeight(i);
    }
    rect.setHeight(tableHeight);

    ui->tableWidget->setGeometry(rect);
}

void MainWindow::fillTable()
{
    QTableWidget* table = this->ui->tableWidget;

    // Tabelle leeren
    table->clear();
    table->setRowCount(agency->getNumberOfBookings());
    QStringList header;
    header.append("Buchungsnummer");
    header.append("Preis");
    header.append("Kunde");
    header.append("Reisenummer");
    table->setHorizontalHeaderLabels(header);

    // Tabelle füllen
    for (int row=0; row<agency->getNumberOfBookings(); row++) {
        table->setItem(row, 0, new QTableWidgetItem(tr("%1").arg(
                                                        agency->getBookingByNo(row)->getId())));
        table->setItem(row, 1, new QTableWidgetItem(tr("%1").arg(
                                                        agency->getBookingByNo(row)->getPrice())));
        table->setItem(row, 2, new QTableWidgetItem(tr("%1").arg(
                                                        QString::fromStdString(agency->findCustomer(agency->findTravel(agency->getBookingByNo(row)->getTravelId())->getCustomerId())->getName()))));
        table->setItem(row, 3, new QTableWidgetItem(tr("%1").arg(
                                                        agency->getBookingByNo(row)->getTravelId())));
    }
}

void MainWindow::on_actionEinlesen_2_triggered()
{
    // Infobox anzeigen

    //agency->clearBookings();
    agency->deleteRecords();
    try {
    std::string ergstring = agency->readFile();
    QMessageBox::information(nullptr,"Ergebnis - Eingelesene Daten",QString::fromStdString(ergstring));
    }
    catch(int z) {
        QMessageBox::critical(nullptr,"Fehler beim Einlesen der Daten",QString::fromStdString("Fehler in Zeile " + to_string(z)));
        agency->deleteRecords();
    }
    fillTable();
}

void MainWindow::on_actionProgramm_beenden_triggered()
{
    this->close();
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    ui->groupBox->setHidden(false);

    Booking* buchung = this->agency->findBooking(this->ui->tableWidget->item(row,0)->text().toLong());

    this->ui->labelBuchungsnummer->setText(QString::fromStdString(to_string(buchung->getId())));

    string fromDate = buchung->getFromDate();

    string s = fromDate.substr(0,4);
    int n = stoi(s);
    string s2 = fromDate.substr(6,2);
    int n2 = stoi(s2);
    QDate fromDateObject(n,stoi(fromDate.substr(4,2)),n2);
    this->ui->calendarWidget->setDateEditEnabled(false);
    this->ui->calendarWidget->setSelectedDate(fromDateObject);

    string toDate = buchung->getToDate();
    QDate toDateObject(stoi(toDate.substr(0,4)),stoi(toDate.substr(4,2)),stoi(toDate.substr(6,2)));
    this->ui->calendarWidget_2->setDateEditEnabled(false);
    this->ui->calendarWidget_2->setSelectedDate(toDateObject);

    //Preis precision
    stringstream stream;
    stream << fixed << setprecision(2) << buchung->getPrice();

    this->ui->lineEdit_Preis->setText(QString::fromStdString(stream.str()+"€"));
    this->ui->lineEdit_Reise->setText(QString::fromStdString(to_string(buchung->getTravelId())));
    this->ui->lineEdit_Kunde->setText(QString::fromStdString(
                                          agency->findCustomer(
                                              agency->findTravel(
                                                  agency->getBookingByNo(row)->getTravelId())->getCustomerId()
                                              )->getName()));

    if(Flightbookings* flug = dynamic_cast<Flightbookings*>(buchung)) {
        this->ui->groupBox_V->setTitle("Flugdetails");
        this->ui->label_V1->show();
        this->ui->label_V2->show();
        this->ui->label_V3->show();
        this->ui->lineEdit_V1->show();
        this->ui->lineEdit_V2->show();
        this->ui->lineEdit_V3->show();
        this->ui->label_V1->setText("Startflughafen");
        this->ui->label_V2->setText("Zielflughafen");
        this->ui->label_V3->setText("Sitzpräferenz");
        this->ui->lineEdit_V1->setText(QString::fromStdString(flug->getFromDest()));
        this->ui->lineEdit_V2->setText(QString::fromStdString(flug->getToDest()));
        this->ui->lineEdit_V3->setText(QString::fromStdString(flug->showDetails()));
    }
    else if(HotelBookings* hotel = dynamic_cast<HotelBookings*>(buchung)) {
        this->ui->groupBox_V->setTitle("Hoteldetails");
        this->ui->label_V1->show();
        this->ui->label_V2->show();
        this->ui->label_V3->show();
        this->ui->lineEdit_V1->show();
        this->ui->lineEdit_V2->show();
        this->ui->lineEdit_V3->show();
        this->ui->label_V1->setText("Hotelname");
        this->ui->label_V2->setText("Stadt");
        this->ui->label_V3->setText("Raucher?");
        this->ui->lineEdit_V1->setText(QString::fromStdString(hotel->getHotel()));
        this->ui->lineEdit_V2->setText(QString::fromStdString(hotel->getTown()));
        this->ui->lineEdit_V3->setText(QString::fromStdString(hotel->getSmoke() ? "Ja" : "Nein"));
    }
    else if(RentalCarReservation* car = dynamic_cast<RentalCarReservation*>(buchung)) {
        this->ui->groupBox_V->setTitle("Autodetails");
        this->ui->label_V1->show();
        this->ui->label_V2->show();
        this->ui->label_V3->show();
        this->ui->lineEdit_V1->show();
        this->ui->lineEdit_V2->show();
        this->ui->lineEdit_V3->show();
        this->ui->label_V1->setText("Pickup");
        this->ui->label_V2->setText("Return");
        this->ui->label_V3->setText("Versicherung");
        this->ui->lineEdit_V1->setText(QString::fromStdString(car->getPickupLocation()));
        this->ui->lineEdit_V2->setText(QString::fromStdString(car->getReturnLocation()));
        this->ui->lineEdit_V3->setText(QString::fromStdString(car->showDetails()));
    }
}

void MainWindow::on_actionNeue_Buchung_anlegen_triggered()
{
    BookingDialog* dialog = new BookingDialog(this, agency);
    //dialog->setAgency(agency);
    dialog->exec();
    fillTable();
}

void MainWindow::on_actionSpeichern_unter_triggered()
{
    Booking* b = nullptr;
    string filename = QFileDialog::getSaveFileName().toStdString();
    ofstream f;
    f.open(filename, ios::out);
    if (!f.is_open()) throw ios_base::failure("Fehler beim Öffnen der Datei!");
    for (int i=0; i<agency->getNumberOfBookings(); i++) {
        b = agency->getBookingByNo(i);
        // Spalte 1
        if (dynamic_cast<Flightbookings*>(b))
            f << "F";
        else if (dynamic_cast<HotelBookings*>(b))
            f << "H";
        else if (dynamic_cast<RentalCarReservation*>(b))
            f << "R";
        else {
            throw ios_base::failure("Fehler beim Speichern: Unbekannter Typ in Zeile "+to_string(i+1));
        }
        f << "|";
        // Spalte 2
        f << b->getId() << "|";
        // Spalte 3
        f << b->getPrice() << "|";
        // Spalte 4
        f << b->getFromDate() << "|";
        // Spalte 5
        f << b->getToDate() << "|";
        // Spalte 6
        f << b->getTravelId() << "|";
        // Spalte 7
        f << agency->findCustomer(agency->findTravel(b->getTravelId())->getCustomerId())->getId() << "|";
        // Spalte 8
        f << agency->findCustomer(agency->findTravel(b->getTravelId())->getCustomerId())->getName() << "|";
        // Spalte 9-12
        if (Flightbookings* flug = dynamic_cast<Flightbookings*>(b))
        {
            f << flug->getFromDest() << "|" << flug->getToDest() << "|" << flug->getAirline() << "|" << flug->getSeatPref();
        }
        else if (HotelBookings* hotel = dynamic_cast<HotelBookings*>(b))
        {
            f << hotel->getHotel() << "|" << hotel->getTown() << "|" << hotel->getSmoke();
        }
        else if (RentalCarReservation* car = dynamic_cast<RentalCarReservation*>(b))
        {
            f << car->getPickupLocation() << "|" << car->getReturnLocation() << "|" << car->getCompany() << "|" << car->getInsurance();
        }
        f << '\n';
    }
    f.close();

    QMessageBox::information(nullptr,"Erfolgreich","Speichern erfolgreich!");
}

void MainWindow::on_actionReisen_pr_fen_triggered()
{
    CheckTravelsDialog* dialog = new CheckTravelsDialog(this, agency);
    dialog->exec();
}
