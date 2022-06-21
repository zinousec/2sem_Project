QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_task3_class_test.cpp \
    ../server/task3_Marco.cpp

HEADERS += \
    ../server/task3_Marco.h
