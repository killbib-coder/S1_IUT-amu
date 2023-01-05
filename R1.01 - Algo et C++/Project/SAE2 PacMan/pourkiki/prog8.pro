TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        entite.cpp \
        main.cpp
        
include(MinGL2/mingl.pri)

HEADERS += \
    entite.h
