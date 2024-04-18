QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clickablewidget.cpp \
    framesequencewidget.cpp \
    hiddentextwidget.cpp \
    illusionss.cpp \
    main.cpp \
    mainwindow.cpp \
    qimprovedslider.cpp \
    videowidget.cpp \
    widgetbutton.cpp

HEADERS += \
    clickablewidget.h \
    framesequencewidget.h \
    hiddentextwidget.h \
    illusionss.h \
    mainwindow.h \
    qimprovedslider.h \
    videowidget.h \
    widgetbutton.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
