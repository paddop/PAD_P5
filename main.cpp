#include "mainwindow.h"
#include <QApplication>

#include "test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Test t;
    QTest::qExec(&t);

    return a.exec();
}
