#-------------------------------------------------
#
# Project created by QtCreator 2014-01-22T13:01:31
#
#-------------------------------------------------

QT       += core \
            gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jan2014
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    worldobject.cpp \
    person.cpp \
    relationship.cpp \
    controller.cpp \
    bulkloader.cpp \
    action.cpp \
    location.cpp \
    locationloader.cpp \
    form.cpp \
    director.cpp \
    worldinterpreter.cpp \
    story.cpp \
    storygoal.cpp

HEADERS += \
    worldobject.h \
    person.h \
    relationship.h \
    controller.h \
    bulkloader.h \
    action.h \
    location.h \
    locationloader.h \
    form.h \
    director.h \
    worldinterpreter.h \
    story.h \
    storygoal.h

INCLUDEPATH += C:\boost_1_55_0

FORMS += \
    form.ui
