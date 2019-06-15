#include "bookingdialog.h"
#include "ui_bookingdialog.h"
#include "booking.h"
#include "flightbookings.h"
#include "hotelbookings.h"
#include "rentalcarreservation.h"
#include <QMessageBox>

BookingDialog::BookingDialog(QWidget *parent, TravelAgency* agency) :
    QDialog(parent),
    ui(new Ui::BookingDialog),
    agency(agency)
{
    ui->setupUi(this);
    this->ui->label_var1->setText("Startflughafen");
    this->ui->label_var2->setText("Zielflughafen");
    this->ui->label_var3->setText("Airline");
    this->ui->label_var4->setText("Sitzpräferenz");
    this->ui->smokeInput->hide();
    this->ui->insuranceInput->hide();
}

BookingDialog::~BookingDialog()
{
    delete ui;
}

void BookingDialog::on_buttonBox_accepted()
{
    string datumVon, datumBis;
    datumVon = "";
    datumVon += to_string(this->ui->dateEdit1->date().year());
    int month = this->ui->dateEdit1->date().month();
    if (month<10) datumVon += "0";
    datumVon += to_string(month);
    datumVon += to_string(this->ui->dateEdit1->date().day());
    datumBis = "";
    datumBis += to_string(this->ui->dateEdit2->date().year());
    month = this->ui->dateEdit2->date().month();
    if (month<10) datumBis += "0";
    datumBis += to_string(month);
    datumBis += to_string(this->ui->dateEdit2->date().day());
    vector<string> details = {};
    string smokeStr;
    int status = 0;
    switch (this->ui->comboBox->currentIndex()) {
    case 0:
        details.push_back(this->ui->lineEdit_1->text().toStdString());
        details.push_back(this->ui->lineEdit_2->text().toStdString());
        details.push_back(this->ui->lineEdit_3->text().toStdString());
        if(this->ui->seatPrefInput->currentText().toStdString() == "Fenster")
            details.push_back("W");
        else {
            details.push_back("A");
        }
        status = agency->createBooking('F',this->ui->preisInput->text().toDouble(),datumVon,datumBis,this->ui->travelIDInput->text().toDouble(),details);
        break;
    case 1:
        details.push_back(this->ui->lineEdit_1->text().toStdString());
        details.push_back(this->ui->lineEdit_2->text().toStdString());
        smokeStr = "0";
        if (this->ui->smokeInput->checkState()) smokeStr = "1";
        details.push_back(smokeStr);
        status = agency->createBooking('H',this->ui->preisInput->text().toDouble(),datumVon,datumBis,this->ui->travelIDInput->text().toDouble(),details);
        break;
    case 2:
        details.push_back(this->ui->lineEdit_1->text().toStdString());
        details.push_back(this->ui->lineEdit_2->text().toStdString());
        details.push_back(this->ui->lineEdit_3->text().toStdString());
        details.push_back(this->ui->insuranceInput->text().toStdString());
        status = agency->createBooking('R',this->ui->preisInput->text().toDouble(),datumVon,datumBis,this->ui->travelIDInput->text().toDouble(),details);
        break;
    }
    if (status == -1)
        QMessageBox::information(nullptr,"Fehler","Ungültige Travel-ID");
}

void BookingDialog::setAgency(TravelAgency *value)
{
    agency = value;
}

void BookingDialog::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        this->ui->lineEdit_3->setEnabled(true);
        this->ui->label_var1->setText("Startflughafen");
        this->ui->label_var2->setText("Zielflughafen");
        this->ui->label_var3->setText("Airline");
        this->ui->label_var4->setText("Sitzpräferenz");
        this->ui->seatPrefInput->show();
        this->ui->smokeInput->hide();
        this->ui->insuranceInput->hide();
        break;
    case 1:
        this->ui->lineEdit_3->setEnabled(false);
        this->ui->label_var1->setText("Hotelname");
        this->ui->label_var2->setText("Stadt");
        this->ui->label_var3->setText("");
        this->ui->label_var4->setText("Raucher?");
        this->ui->seatPrefInput->hide();
        this->ui->smokeInput->show();
        this->ui->insuranceInput->hide();
        break;
    case 2:
        this->ui->lineEdit_3->setEnabled(true);
        this->ui->label_var1->setText("Pickup bei");
        this->ui->label_var2->setText("Rückgabe bei");
        this->ui->label_var3->setText("Firma");
        this->ui->label_var4->setText("Versicherung");
        this->ui->seatPrefInput->hide();
        this->ui->smokeInput->hide();
        this->ui->insuranceInput->show();
        break;
    }
}
