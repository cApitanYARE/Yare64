#include "motherboard.h"
#include <QProcess>
#include <QDebug>
#include <QStringList>
#include <QVBoxLayout>
#include <QLabel>
#include <Windows.h>

motherboard::motherboard(QWidget *parent)
    : QWidget(parent) {
    this->setStyleSheet("background-color: #cecccc;");

    Vlayout = new QVBoxLayout(this);
    Resolution = new QLabel(this);
    outPutInfo = new QLabel(this);

    DISPLAY_DEVICE dd;
    DEVMODE devmode;
    dd.cb = sizeof(dd);
    devmode.dmSize = sizeof(devmode);
    EnumDisplayDevices(NULL, 0, &dd, 0);
    EnumDisplaySettings(dd.DeviceName, ENUM_CURRENT_SETTINGS, &devmode);

    Resolution->setText("Current resolution: " + QString::number(devmode.dmPelsWidth) + " x " + QString::number(devmode.dmPelsHeight));

    QProcess process;

    // Start PowerShell and run the command to get video controller information
    process.start("powershell", QStringList() << "-Command"
                                              << "Get-WmiObject Win32_VideoController | Select-Object Name,AdapterCompatibility,AdapterRAM,DriverVersion | Format-List");
    process.waitForFinished();
    QString output = process.readAllStandardOutput().trimmed();
    QStringList lines = output.split("\n", Qt::SkipEmptyParts);

    QString info;
        for (const QString &line : lines) {
            QString trimmedLine = line.trimmed();

            if (trimmedLine.startsWith("AdapterRAM")) {
                QString value = trimmedLine.split(":").last().trimmed();
                bool ok;
                quint64 ramBytes = value.toULongLong(&ok);
                if (ok) {
                    quint64 ramMb = ramBytes / (1024 * 1024);
                    trimmedLine = "AdapterRAM : " + QString::number(ramMb) + " Mb";
                }
            }
           info += trimmedLine + "\n\n";
        }

    outPutInfo->setText(info);

    outPutInfo->setStyleSheet("font-weight: bold; font-size:16px;");
    Resolution->setStyleSheet("font-weight: bold; font-size:16px;");

    Vlayout->setAlignment(Qt::AlignVCenter);
    Vlayout->addWidget(outPutInfo);
    Vlayout->addWidget(Resolution);
    this->setLayout(Vlayout);
}

motherboard::~motherboard() {}
