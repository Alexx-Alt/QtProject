QT       += core gui sql network
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coursespage.cpp \
    database.cpp \
    forumpage.cpp \
    jwt.cpp \
    login.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    profile.cpp \
    testframe.cpp \
    uisetup.cpp

HEADERS += \
    coursespage.h \
    database.h \
    forumpage.h \
    jwt.h \
    login.h \
    mainpage.h \
    mainwindow.h \
    profile.h \
    testframe.h \
    uisetup.h

FORMS += \
    coursespage.ui \
    forumpage.ui \
    login.ui \
    mainpage.ui \
    mainwindow.ui \
    profile.ui \
    testframe.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Scr.qrc
