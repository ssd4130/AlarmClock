#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow *ui;
    void alarmCheck();
    ~MainWindow();

private slots:
    void on_actionScan_Device_triggered();

    void on_actionAdd_Device_2_triggered();

    void on_timeEdit_userTimeChanged(const QTime &time);

    void on_setAlarmButton_clicked();

    void on_toggleAlarmButton_clicked();

    void showTime();

    void play();

    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
