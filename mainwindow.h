#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <Qwidget>
#include <QCursor>

#include "motherboard.h"
#include "proccersoer.h"
#include "os.h"
#include "ram.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *mainWidget;

    QPushButton *closeWindow;

    QPushButton *proccersoerButton;
    QPushButton *motherboardButton;
    QPushButton *RAMButton;
    QPushButton *OSButton;

    QHBoxLayout *layoutButton;
    QVBoxLayout *mainLayout;

    //wigetButtons
    motherboard *motherboardWidget;
    proccersoer *proccersoerWidget;
    OS *osWidget;
    RAM *ramWidget;

    QWidget *press;
    void resetButtonStyles();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
