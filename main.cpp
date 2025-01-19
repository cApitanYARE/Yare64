#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(400,390);

    w.setWindowIcon(QIcon("./yare64.ico"));
    QApplication::setWindowIcon(QIcon("./yare64.png"));

    qDebug() << "Current working directory:" << QDir::currentPath();

    w.setWindowFlag(Qt::FramelessWindowHint);
    w.setWindowFlag(Qt::NoDropShadowWindowHint);  // Якщо є тінь
    w.setAttribute(Qt::WA_NoSystemBackground);   // Прибрати фон
    w.setAttribute(Qt::WA_TranslucentBackground); // Для прозорого фону

    w.show();
    return a.exec();
}
