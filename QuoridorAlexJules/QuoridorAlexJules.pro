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
    Player.cpp \
    Side.cpp \
    subject.cpp \
    QuoridorConsole.cpp \
    Test.cpp

HEADERS += \
    Frame.h \
    Game.h \
    Player.h \
    Board.h \
    Side.h \
    QuoridorExceptions.h \
    observer.h \
    subject.h \
    QuoridorConsole.h \
    keyboard.hpp \
    stringConvert.hpp \
    Test.h

DISTFILES +=

