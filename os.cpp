#include "os.h"

OS::OS(QWidget *parent)
:QWidget(parent){
    this->setStyleSheet(""
                        "background-color: #cecccc;"
                        );


    std::vector<QString> nameTitle;
    std::vector<QString> nameSubTittle;
    Vlayout = new QVBoxLayout(this);
    outPutInfo = new QLabel(this);

    QProcess process;
    // Start PowerShell and run the command to get video controller information
    process.start("powershell", QStringList()
                                    << "-NoProfile"
                                    << "-Command"
                                    << "$OutputEncoding = [Console]::OutputEncoding = [System.Text.Encoding]::UTF8; "
                                    << "Get-CimInstance Win32_OperatingSystem | Select-Object Caption, Version, Manufacturer, OSArchitecture, RegisteredUser, LastBootUpTime");
    process.waitForFinished();
    QString output = QString::fromUtf8(process.readAllStandardOutput().trimmed());
    QStringList lines = output.split("\n", Qt::SkipEmptyParts);


    QString info;
    for (const QString &line : lines) {
        QString cleanedLine;

                cleanedLine += line + " ";


        info += cleanedLine.trimmed() + "\n\n"; // Додаємо очищений рядок
    }

    outPutInfo->setText(info);
    outPutInfo->setStyleSheet("font-weight: bold; font-size:17px;");
    Vlayout->addWidget(outPutInfo);
    Vlayout->setAlignment(Qt::AlignVCenter);
    this->setLayout(Vlayout);
}

OS::~OS(){}
