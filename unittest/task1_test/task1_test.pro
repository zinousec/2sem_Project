QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_task1_class_test.cpp \
    ../server/task1.cpp

HEADERS += \
    ../server/task1.h
