#ifndef RAM_H
#define RAM_H

#include <QWidget>
#include <QProcess>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProcess>
#include <QString>
#include <QTimer>

#include <vector>
#include <windows.h>

class RAM : public QWidget
{
public:
    explicit RAM(QWidget *parent = nullptr);
    ~RAM();


    QHBoxLayout *Hlayout;
    QVBoxLayout *Vlayout;

    QLabel *total;
    QLabel *available;
    QLabel *outPutInfo;
    QLabel *VM;
    QLabel *AM;

    QTimer *availableTimer;
};

#endif // RAM_H
