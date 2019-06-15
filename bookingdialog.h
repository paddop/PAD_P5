#ifndef BOOKINGDIALOG_H
#define BOOKINGDIALOG_H

#include <QDialog>
#include "travelagency.h"

namespace Ui {
class BookingDialog;
}

class BookingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookingDialog(QWidget *parent = nullptr, TravelAgency* agency = nullptr);
    ~BookingDialog();

    void setAgency(TravelAgency *value);

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::BookingDialog *ui;
    TravelAgency* agency;
};

#endif // BOOKINGDIALOG_H
