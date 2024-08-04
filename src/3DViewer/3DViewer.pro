linux-g++ | linux-g++-64 | linux-g++-32 | win32 {
QT += core gui widgets printsupport
LIBS += -lGLU
}
macx {
QT += core gui openglwidgets
LIBS +=-framework OpenGL
}

QMAKE_CFLAGS -= -O2
QMAKE_CFLAGS -= -O1
QMAKE_CXXFLAGS -= -O2
QMAKE_CXXFLAGS -= -O1

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += debug_and_release

INCLUDEPATH += \
    objFileLib \
    ui \
    ui/viewFieldGL \
    3rdparty \
    viewerlib

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ui/viewFieldGL/viewfieldgl.cpp \
    viewerlib/viewerlib.c

HEADERS += \
    mainwindow.h \
    ui/viewFieldGL/viewfieldgl.h \
    gif.h \
    viewerlib/viewerlib.h \
    3rdparty/gif.h

FORMS += \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
