#-------------------------------------------------
#
# Project created by QtCreator 2017-03-13T19:16:08
#
#-------------------------------------------------

QT += widgets

TARGET = FingerPrintScannerDLL
TEMPLATE = lib

DEFINES += FINGERPRINTSCANNERDLL_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += fingerprintscanner.cpp

HEADERS += fingerprintscanner.h\
        fingerprintscannerdll_global.h \
    FingerPrintScanner/fxISO_device.h \
    FingerPrintScanner/fxISO_engine.h \
    FingerPrintScanner/fxISO_Interchange.h \
    FingerPrintScanner/fxISOAFIS.h \
    FingerPrintScanner/fxISOdll.h \
    FingerPrintScanner/fxISOenrdlg.h

LIBS += "C:/TeamProject/FingerPrintScannerDLL/FingerPrintScanner/lib/x64/fxISO_64.lib"
LIBS += "C:/TeamProject/FingerPrintScannerDLL/FingerPrintScanner/lib/x64/fxISOenrdlg_64.lib"

unix {
    target.path = /usr/lib
    INSTALLS += target
}
