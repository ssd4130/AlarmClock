#include "mainwindow.h"
#include "alarmthread.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <QtWidgets>
#include <QPushButton>
#include <QTimer>
#include <iostream>
#include <QTime>
#include <cstddef>
#include <QtCore>
#include <QDebug>

QString alarmString;
QTime alarmTime = QTime();
bool alarmSet;
FILE deviceList;
QTime currentTime;
QTimer *timer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    setWindowTitle(tr("Alarm Clock"));
    showTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

AlarmThread::AlarmThread(){

}

void AlarmThread::run(){
    while(1){
        currentTime = QTime::currentTime();
        if(alarmTime == currentTime && !alarmTime.isNull()){
            system("xmms2 play");
        }
    }
}

void MainWindow::on_toggleAlarmButton_clicked()
{
    if(alarmSet == false){
        alarmSet = true;
        ui->setLabel->setText("          Alarm Set for " + alarmTime.toString());
    }
    else if(alarmSet == true){
        alarmSet = false;
        ui->setLabel->setText("         Alarm Disabled!");
    }
    alarmTime = ui->timeEdit->time();
}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    MainWindow::ui->clockFace->display(text);
}

void MainWindow::on_pushButton_clicked()
{
    system("xmms2 stop");
}
