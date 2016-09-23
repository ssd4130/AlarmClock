#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
#include "alarmthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    AlarmThread thread;
    thread.start();

    return a.exec();
}
