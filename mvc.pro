#-------------------------------------------------
#
# Project created by QtCreator 2019-04-27T18:04:23
#
#-------------------------------------------------

QT       += core



INCLUDEPATH += C:\Opencv\build\install\include

LIBS += C:\Opencv\build\bin\libopencv_core310.dll
LIBS += C:\Opencv\build\bin\libopencv_highgui310.dll
LIBS += C:\Opencv\build\bin\libopencv_imgproc310.dll
LIBS += C:\Opencv\build\bin\libopencv_features2d310.dll
LIBS += C:\Opencv\build\bin\libopencv_calib3d310.dll
LIBS += C:\Opencv\build\bin\libopencv_imgcodecs310.dll




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mvc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        colordetector.cpp \
        colordetectorcontroller.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        colordetector.h \
        colordetectorcontroller.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
