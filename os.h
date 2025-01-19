#ifndef OS_H
#define OS_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProcess>

#include <vector>

#include <windows.h>

class OS : public QWidget
{
public:
    explicit OS(QWidget *parent = nullptr);
    ~OS();


    QHBoxLayout *Hlayout;
    QVBoxLayout *Vlayout;

    QLabel *outPutInfo;
};

#endif // OS_H
