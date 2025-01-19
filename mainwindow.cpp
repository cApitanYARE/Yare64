#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // buttons
    {
        mainWidget = new QWidget(this);
        mainWidget->setObjectName("mainWidget");
        setCentralWidget(mainWidget);

        mainWidget->setStyleSheet(
            "#mainWidget {"
            "background-color: #ede8e8;"
            "}"
            );

        closeWindow = new QPushButton("CLOSE", this);
        closeWindow->setStyleSheet("QPushButton{"
                                   "min-width:400px;"
                                   "max-height:20px;"
                                   "background-color:#f96161;"
                                   "border:1px solid #343131;"
                                   "color:white;"
                                   "letter-spacing:10px;"
                                   "}"
                                   "QPushButton:hover{"
                                   "background-color:#fa3f3f;"
                                   "}");
        closeWindow->setCursor(Qt::PointingHandCursor);


        proccersoerButton = new QPushButton("Proccersoer", this);
        proccersoerButton->setObjectName("allButton");
        proccersoerButton->setStyleSheet("background-color:#cecccc; color:black;");

        motherboardButton = new QPushButton("Graphic Card", this);
        motherboardButton->setObjectName("allButton");

        RAMButton = new QPushButton("RAM", this);
        RAMButton->setObjectName("allButton");

        OSButton = new QPushButton("OS", this);
        OSButton->setObjectName("allButton");

        proccersoerButton->setCursor(Qt::PointingHandCursor);
        motherboardButton->setCursor(Qt::PointingHandCursor);
        RAMButton->setCursor(Qt::PointingHandCursor);
        OSButton->setCursor(Qt::PointingHandCursor);

        this->setStyleSheet(
            "#allButton {"
            "width:70px;"
            "margin-top:20px;"
            "padding:5px;"
            "color:white;"
            "background-color: #343131;"
            "border:none;"
            "}"
            "#allButton:hover{"
            "color:black;"
            "background-color: #cecccc;"
            "}"
            );



        layoutButton = new QHBoxLayout();
        layoutButton->setSpacing(20);
        layoutButton->addWidget(proccersoerButton);
        layoutButton->addWidget(motherboardButton);
        layoutButton->addWidget(RAMButton);
        layoutButton->addWidget(OSButton);
        layoutButton->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    }


    //motherboard
    motherboardWidget = new motherboard(mainWidget);
    motherboardWidget->setFixedSize(380, 300);
    motherboardWidget->setVisible(false);

    //proccersoer
    proccersoerWidget = new proccersoer(mainWidget);
    proccersoerWidget->setFixedSize(380, 300);
    proccersoerWidget->setVisible(true);
    press = proccersoerWidget;
    //OS
    osWidget = new OS(mainWidget);
    osWidget->setFixedSize(380, 300);
    osWidget->setVisible(false);

    //RAM
    ramWidget = new RAM(mainWidget);
    ramWidget->setFixedSize(380, 300);
    ramWidget->setVisible(false);

    // Основний вертикальний макет
    mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    mainLayout->addLayout(layoutButton);
    mainLayout->addWidget(motherboardWidget);
    mainLayout->addWidget(proccersoerWidget);
    mainLayout->addWidget(osWidget);
    mainLayout->addWidget(ramWidget);
    mainWidget->setLayout(mainLayout);

    //connect
    {
        connect(motherboardButton, &QPushButton::clicked, [&]() {
            press->setVisible(false);
            resetButtonStyles();
            motherboardWidget->setVisible(true);
            motherboardButton->setStyleSheet("background-color:#cecccc; color:black;");
            press = motherboardWidget;
        });

        connect(proccersoerButton, &QPushButton::clicked, [&]() {
            press->setVisible(false);
            resetButtonStyles();
            proccersoerWidget->setVisible(true);
            proccersoerButton->setStyleSheet("background-color:#cecccc; color:black;");
            press = proccersoerWidget;
        });

        connect(RAMButton, &QPushButton::clicked, [&]() {
            press->setVisible(false);
            resetButtonStyles();
            ramWidget->setVisible(true);
            RAMButton->setStyleSheet("background-color:#cecccc; color:black;");
            press = ramWidget;
        });

        connect(OSButton, &QPushButton::clicked, [&]() {
            press->setVisible(false);
            resetButtonStyles();
            osWidget->setVisible(true);
            OSButton->setStyleSheet("background-color:#cecccc; color:black;");
            press = osWidget;
        });

        connect(closeWindow, &QPushButton::clicked, [&]() {
            this->close();
        });
    }
}

void MainWindow::resetButtonStyles()
{
    proccersoerButton->setStyleSheet(
        "background-color: #343131; color: white; border: none; padding: 5px;");
    motherboardButton->setStyleSheet(
        "background-color: #343131; color: white; border: none; padding: 5px;");
    RAMButton->setStyleSheet(
        "background-color: #343131; color: white; border: none; padding: 5px;");
    OSButton->setStyleSheet(
        "background-color: #343131; color: white; border: none; padding: 5px;");
}

MainWindow::~MainWindow()
{
    delete ui;

}
