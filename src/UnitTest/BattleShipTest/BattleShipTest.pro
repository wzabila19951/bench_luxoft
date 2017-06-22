include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_testcase.h


SOURCES +=     main.cpp \
    ../../ai.cpp \
    ../../aiturn.cpp \
    ../../corvete.cpp \
    ../../drawer.cpp \
    ../../frigate.cpp \
    ../../gamestate.cpp \
    ../../lifecycle.cpp \
    ../../linkor.cpp \
    ../../main.cpp \
    ../../map.cpp \
    ../../pause.cpp \
    ../../playerturn.cpp \
    ../../ship.cpp \
    ../../sloop.cpp
