TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        entities.cpp \
        main.cpp \
        map.cpp

include(MinGL2/mingl.pri)

HEADERS += \
    entities.h \
    map.h
