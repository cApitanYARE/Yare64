#ifndef PROCCERSOER_H
#define PROCCERSOER_H

#include <vector>

#include <QWidget>
#include <QLabel>
#include <windows.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProcess>
#include <QString>

class proccersoer: public QWidget
{
public:
    explicit proccersoer(QWidget *parent = nullptr);
    ~proccersoer();

    QHBoxLayout *Hlayout;
    QVBoxLayout *Vlayout;

    QLabel *num_of_proc;
    QLabel *outPutInfo;

};

#endif // PROCCERSOER_H
