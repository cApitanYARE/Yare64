#include "ram.h"

RAM::RAM(QWidget *parent)
    : QWidget(parent){

    this->setStyleSheet(""
                        "background-color: #cecccc;");

    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);

    Vlayout = new QVBoxLayout(this);
    total = new QLabel(this);
    available = new QLabel(this);
    outPutInfo = new QLabel(this);
    availableTimer = new QTimer(this);
    AM = new QLabel(this);
    VM = new QLabel(this);

    QProcess process;
    process.start("powershell", QStringList() << "Get-WmiObject -Class Win32_PhysicalMemory | Select-Object Capacity, Speed, Manufacturer");
    process.waitForFinished();
    QString output = process.readAllStandardOutput();
    QStringList lines = output.split("\n", Qt::SkipEmptyParts);

    std::vector<QString> nameTitle;
    std::vector<QString> nameSubTittle;
    for(int i=0;i<lines.size();++i){
        if(i==1){
            QStringList parts = lines[1].split(" ", Qt::SkipEmptyParts);
            for(auto part : parts){
                nameTitle.push_back(part);
            }
        }
        if(i==3){
            QStringList parts = lines[3].split(" ", Qt::SkipEmptyParts);
            for(auto part : parts){
                nameSubTittle.push_back(part);
            }
        }
        if(i==4){
            QStringList parts = lines[4].split(" ", Qt::SkipEmptyParts);
            for(auto part : parts){
                nameSubTittle.push_back(part);
            }
        }
    }
    quint64 sizeInBytes = nameSubTittle[0].toULongLong();
    double sizeInMb = sizeInBytes / 1024.0 / 1024.0;
    QString text = nameTitle[0] + " : " + QString::number(sizeInMb) + " Mb";
    outPutInfo->setText(outPutInfo->text() + text + "\n");
    outPutInfo->setText(outPutInfo->text()+ nameTitle[1] + " : " + nameSubTittle[1] + "\n");
    outPutInfo->setText(outPutInfo->text()+ nameTitle[2] + " : " + nameSubTittle[2] + "\n");

    outPutInfo->setStyleSheet("font-weight: bold; font-size:20px;");
    total->setStyleSheet("font-weight: bold; font-size:20px;");
    available->setStyleSheet("font-weight: bold; font-size:20px;");



    total->setText("Total RAM: " + QString::number(statex.ullTotalPhys / 1024 / 1024) + " Mb");

    VM->setText("Total Virtual Memory:: " + QString::number(statex.ullTotalVirtual / 1024 / 1024 / 1024) + " Gb");
    AM->setText("Available Virtual Memory: " + QString::number(statex.ullAvailVirtual / 1024 / 1024 / 1024) + " Gb\n");

    VM->setStyleSheet("font-weight: bold; font-size:20px;");
    AM->setStyleSheet("font-weight: bold; font-size:20px; ");



    connect(availableTimer,&QTimer::timeout,[this]{
        MEMORYSTATUSEX statex;
        statex.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&statex);

        available->setText("Available RAM: "+ QString::number(statex.ullAvailPhys / 1024 / 1024) + " Mb");
    });
    availableTimer->start(100);

    Vlayout->addWidget(outPutInfo);
    Vlayout->addWidget(total);
    Vlayout->addWidget(available);
    Vlayout->addWidget(VM);
    Vlayout->addWidget(AM);
    Vlayout->setAlignment(Qt::AlignVCenter);
    this->setLayout(Vlayout);
}

RAM::~RAM() {}
