QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algorythms/algorythm.cpp \
    algorythms/left_algorythm.cpp \
    algorythms/random_algorythm.cpp \
    algorythms/right_algorythm.cpp \
    direction.cpp \
    gamecontroller.cpp \
    main.cpp \
    maze.cpp \
    micromouse.cpp \
    mouse.cpp \
    tile.cpp \
    wall.cpp

HEADERS += \
    algorythms/algorythm.h \
    algorythms/left_algorythm.h \
    algorythms/random_algorythm.h \
    algorythms/right_algorythm.h \
    direction.h \
    gamecontroller.h \
    maze.h \
    micromouse.h \
    mouse.h \
    tile.h \
    wall.h

FORMS += \
    micromouse.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    class_model.qmodel \
    example2.txt \
    example3.txt \
    example4.txt \
    example5.txt

RESOURCES += \
    resources.qrc

STATECHARTS += \
    stan.scxml
