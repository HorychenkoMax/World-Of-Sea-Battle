QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battlefieldscene.cpp \
    battlemodel.cpp \
    boat.cpp \
    cellmatrix.cpp \
    connectionproperties.cpp \
    enemytablescene.cpp \
    locationselectionscene.cpp \
    locationselectionwindow.cpp \
    main.cpp \
    maingamewindow.cpp \
    mainwindow.cpp \
    mytablescene.cpp \
    optionswindow.cpp \
    socketserver.cpp

HEADERS += \
    battlefieldscene.h \
    battlemodel.h \
    boat.h \
    cellmatrix.h \
    celltype.h \
    connectionproperties.h \
    direction.h \
    enemytablescene.h \
    locationselectionscene.h \
    locationselectionwindow.h \
    maingamewindow.h \
    mainwindow.h \
    mytablescene.h \
    optionswindow.h \
    socketserver.h

FORMS += \
    locationselectionwindow.ui \
    maingamewindow.ui \
    mainwindow.ui \
    optionswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recources.qrc

DISTFILES +=
