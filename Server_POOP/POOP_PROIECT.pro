QT -= gui
QT += network
QT += core
QT+=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cfactoryprotocol.cpp \
    completareraportinvoire.cpp \
    completareraportpermisie.cpp \
    cprotocol.cpp \
    database.cpp \
    genereazaservicii.cpp \
    iprotocol.cpp \
    main.cpp \
    mainwindow.cpp \
    protocollogin.cpp \
    protocolregister.cpp \
    raspunsAprobareRaport.cpp \
    resetareparola.cpp \
    respingerepermisii.cpp \
    schimbaresector.cpp \
    schimbareserviciu.cpp \
    server.cpp \
    solicitarepermisie.cpp \
    thread.cpp \
    vizualizarepermisii.cpp \
    vizualizarerapoarte.cpp \
    vizualizareraportspecific.cpp \
    vizualizaresectordupastudent.cpp \
    vizualizareserviciudupazi.cpp \
    vizualizarestudentdupasector.cpp

HEADERS += \
    ProtocolList.h \
    cfactoryprotocol.h \
    completareraportinvoire.h \
    completareraportpermisie.h \
    cprotocol.h \
    database.h \
    genereazaservicii.h \
    iprotocol.h \
    mainwindow.h \
    protocollogin.h \
    protocolregister.h \
    raspunsAprobareRaport.h \
    resetareparola.h \
    respingerepermisii.h \
    schimbaresector.h \
    schimbareserviciu.h \
    server.h \
    solicitarepermisie.h \
    thread.h \
    vizualizarepermisii.h \
    vizualizarerapoarte.h \
    vizualizareraportspecific.h \
    vizualizaresectordupastudent.h \
    vizualizareserviciudupazi.h \
    vizualizarestudentdupasector.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
