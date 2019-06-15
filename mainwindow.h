#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "travelagency.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionEinlesen_2_triggered();

    void on_actionProgramm_beenden_triggered();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_actionNeue_Buchung_anlegen_triggered();

    void on_actionSpeichern_unter_triggered();

    void on_actionReisen_pr_fen_triggered();

private:
    Ui::MainWindow *ui;
    TravelAgency* agency;
    void adjustTableSize();
    void fillTable();
};

#endif // MAINWINDOW_H
