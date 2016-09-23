#ifndef ALARMTHREAD_H
#define ALARMTHREAD_H

#include <QThread>
#include <QtCore>


class AlarmThread : public QThread
{
    public:
        AlarmThread();
        void run();
};

#endif // ALARMTHREAD_H
