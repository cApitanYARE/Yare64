QT += core gui widgets


CONFIG += c++17

win32: LIBS += -lpsapi -luser32 -lkernel32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    mainwindow.h \
    motherboard.h \
    os.h \
    proccersoer.h \
    ram.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    motherboard.cpp \
    os.cpp \
    proccersoer.cpp \
    ram.cpp

FORMS += \
    mainwindow.ui

INCLUDEPATH += D:\qt\6.8.1\msvc2022_64\lib
LIBS += -LD:\qt\6.8.1\msvc2022_64\lib

# Визначаємо файли, які потрібно скопіювати
ICON_FILES += yare64.ico yare64.png

# Автоматичне копіювання іконок у директорію збірки
for (icon, ICON_FILES) {
    QMAKE_POST_LINK += $$quote(copy /Y $$PWD/$${icon} $$OUT_PWD/)&
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
