#ifndef CHECKTRAVELSDIALOG_H
#define CHECKTRAVELSDIALOG_H

#include <QDialog>
#include "travelagency.h"

namespace Ui {
class CheckTravelsDialog;
}

class CheckTravelsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckTravelsDialog(QWidget *parent = nullptr, TravelAgency* agency = nullptr);
    ~CheckTravelsDialog();

private:
    Ui::CheckTravelsDialog *ui;
    TravelAgency* agency;
};

#endif // CHECKTRAVELSDIALOG_H
