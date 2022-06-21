QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_task6test.cpp \
    ../task6.cpp

DISTFILES +=

HEADERS += \
    ../task6.h
