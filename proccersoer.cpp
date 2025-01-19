#include "proccersoer.h"
#include <QStringList>

proccersoer::proccersoer(QWidget *parent)
    : QWidget(parent){

    this->setStyleSheet("background-color: #cecccc;");

    Vlayout = new QVBoxLayout(this);

    num_of_proc = new QLabel(this);
    outPutInfo = new QLabel(this);

    QProcess process;
    process.start("powershell", QStringList() << "-Command" << "Get-CimInstance Win32_Processor | Select-Object Name, Manufacturer, MaxClockSpeed, NumberOfCores, NumberOfLogicalProcessors, Architecture, ProcessorId");
    process.waitForFinished();
    QString output = process.readAllStandardOutput();

    QStringList lines = output.split("\n", Qt::SkipEmptyParts);

    QString info;
    for (const QString &line : lines) {
        if (line.contains("Name")) {
            QStringList parts = line.split(":", Qt::SkipEmptyParts);
            if (parts.size() > 1) {
                QString rawName = parts[1].trimmed();

                int startIndex = rawName.indexOf("i");
                if (startIndex != -1) {
                    QString modelName = rawName.mid(startIndex, rawName.indexOf(" ", startIndex) - startIndex);
                    info += "Model                          :" + modelName + "\n\n";
                    continue;
                }
            }
        }

        if (line.contains("ProcessorId")) continue;

        info += line + "\n\n";
    }

    outPutInfo->setText(info.trimmed());

    outPutInfo->setStyleSheet("font-weight: bold; font-size:20px;");
    Vlayout->addWidget(outPutInfo);
    Vlayout->addWidget(num_of_proc);
    Vlayout->setAlignment(Qt::AlignVCenter);
    this->setLayout(Vlayout);
    this->update();
}

proccersoer::~proccersoer() {}
