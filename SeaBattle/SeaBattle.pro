QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    models/battlemodel.cpp \
    models/boat.cpp \
    models/cellmatrix.cpp \
    models/connectionproperties.cpp \
    scenes/battlefieldscene.cpp \
    scenes/enemytablescene.cpp \
    scenes/locationselectionscene.cpp \
    scenes/mytablescene.cpp \
    socket/socketclient.cpp \
    socket/socketserver.cpp \
    windows/locationselectionwindow.cpp \
    windows/maingamewindow.cpp \
    windows/mainwindow.cpp \
    windows/optionswindow.cpp


HEADERS += \
    models/battlemodel.h \
    models/boat.h \
    models/cellmatrix.h \
    models/celltype.h \
    models/connectionproperties.h \
    models/direction.h \
    scenes/battlefieldscene.h \
    scenes/enemytablescene.h \
    scenes/locationselectionscene.h \
    scenes/mytablescene.h \
    socket/socketclient.h \
    socket/socketserver.h \
    windows/locationselectionwindow.h \
    windows/maingamewindow.h \
    windows/mainwindow.h \
    windows/optionswindow.h


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

DISTFILES += \
    resources/game_window_images/battlefildImage2.jpg \
    resources/game_window_images/fog.png \
    resources/game_window_images/gameWindowBackground.jpg \
    resources/game_window_images/sight.png \
    resources/main_window_images/SeaBatleMenuIcon.jpg \
    resources/main_window_images/mainWindowBackground.jpg \
    resources/main_window_images/optionWindowBackground.jpg \
    resources/main_window_images/windowIcon.jpg \
    resources/ships_images/old/four_battleship/four_battleship-down.png \
    resources/ships_images/old/four_battleship/four_battleship-left.png \
    resources/ships_images/old/four_battleship/four_battleship-right.png \
    resources/ships_images/old/four_battleship/four_battleship-up.png \
    resources/ships_images/old/four_battleship/four_battleship_cut/four_battleship-removebg_1.png \
    resources/ships_images/old/four_battleship/four_battleship_cut/four_battleship-removebg_2.png \
    resources/ships_images/old/four_battleship/four_battleship_cut/four_battleship-removebg_3.png \
    resources/ships_images/old/four_battleship/four_battleship_cut/four_battleship-removebg_4.png \
    resources/ships_images/old/one_battleship/one_battleship-down.png \
    resources/ships_images/old/one_battleship/one_battleship-left.png \
    resources/ships_images/old/one_battleship/one_battleship-right.png \
    resources/ships_images/old/one_battleship/one_battleship-up.png \
    resources/ships_images/old/three_battleship/three_battleship-down.png \
    resources/ships_images/old/three_battleship/three_battleship-left.png \
    resources/ships_images/old/three_battleship/three_battleship-right.png \
    resources/ships_images/old/three_battleship/three_battleship-up.png \
    resources/ships_images/old/three_battleship/three_battleship_cut/three_battleship-removebg_1.png \
    resources/ships_images/old/three_battleship/three_battleship_cut/three_battleship-removebg_2.png \
    resources/ships_images/old/three_battleship/three_battleship_cut/three_battleship-removebg_3.png \
    resources/ships_images/old/two_battleship/two_battleship-down.png \
    resources/ships_images/old/two_battleship/two_battleship-left.png \
    resources/ships_images/old/two_battleship/two_battleship-right.png \
    resources/ships_images/old/two_battleship/two_battleship-up.png \
    resources/ships_images/old/two_battleship/two_battleship_cut/two_battleship-removebg_1.png \
    resources/ships_images/old/two_battleship/two_battleship_cut/two_battleship-removebg_2.png
