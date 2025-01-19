#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include <QWidget>
#include <QProcess>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QProcess>
#include <QString>


#include <windows.h>

class motherboard : public QWidget
{
public:
    explicit motherboard(QWidget *parent = nullptr);
    ~motherboard();

    QHBoxLayout *Hlayout;
    QVBoxLayout *Vlayout;

    QLabel* Resolution;
    QLabel *outPutInfo;
};

#endif // MOTHERBOARD_H
