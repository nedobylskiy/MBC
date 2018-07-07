#-------------------------------------------------
#
# Project created by QtCreator 2012-10-12T19:27:52
#
#-------------------------------------------------

QT       += core gui webkit network
QT += widgets

TARGET = MBC
TEMPLATE = app


SOURCES += main.cpp\
        mbcwindow.cpp \
    player1.cpp \
    player2.cpp \
    playlist.cpp \
    library.cpp \
    previewplayer.cpp \
    inputsystem.cpp \
    encoderslist.cpp \
    encoder.cpp \
    configure.cpp \
    vk.cpp \
    djpanel.cpp \
    sample.cpp \
    wskype.cpp \
    jingles.cpp \
    playlisthistory.cpp

HEADERS  += mbcwindow.h \
    player1.h \
    player2.h \
    bassmix.h \
    bassenc.h \
    bass.h \
    playlist.h \
    library.h \
    previewplayer.h \
    inputsystem.h \
    encoderslist.h \
    encoder.h \
    configure.h \
    vk.h \
    djpanel.h \
    sample.h \
    wskype.h \
    jingles.h \
    playlisthistory.h

FORMS    += mbcwindow.ui \
    player1.ui \
    player2.ui \
    playlist.ui \
    library.ui \
    previewplayer.ui \
    inputsystem.ui \
    encoderslist.ui \
    encoder.ui \
    configure.ui \
    vk.ui \
    djpanel.ui \
    sample.ui \
    wskype.ui \
    jingles.ui \
    playlisthistory.ui


RESOURCES += \
    res.qrc

unix:LIBS += -lbass -ltag -lbassenc -lbassmix#-L/devellibs/libbass.so
win32:LIBS += E:/MBC/bass.lib E:/MBC/bassenc.lib E:/MBC/bassmix.lib E:/MBC/libtag.dll.a E:/MBC/libtag_c.dll.a E:/MBC/tags.lib
