TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x
SOURCES += \
    Board.cpp \
    Frame.cpp \
    Game.cpp \
    Main.cpp \
    Player.cpp

HEADERS += \
    Case.h \
    Frame.h \
    Game.h \
    Main.h \
    Player.h \
    Board.h \
    Side.h

DISTFILES +=

