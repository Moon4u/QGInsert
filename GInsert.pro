#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T10:58:52
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GInsert
TEMPLATE = app


SOURCES += \
	main.cpp\
	mainwindow.cpp \
    gsuggestcompletion.cpp \
    searchbox.cpp \
    au3/sendkeys.cpp \
    au3/variant_datatype.cpp

HEADERS  += \
	mainwindow.h \
    gsuggestcompletion.h \
    searchbox.h \
    au3/sendkeys.h \
    au3/variant_datatype.h

FORMS	+= mainwindow.ui

QMAKE_CXXFLAGS += -static
