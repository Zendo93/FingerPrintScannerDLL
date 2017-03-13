#ifndef FINGERPRINTSCANNER_H
#define FINGERPRINTSCANNER_H

#include "fingerprintscannerdll_global.h"
#include <QString>
#include <QByteArray>
#include <QBuffer>
#include "FingerPrintScanner/fxISOdll.h"
#include "FingerPrintScanner/fxISOAFIS.h"
#include "FingerPrintScanner/fxISOenrdlg.h"
#include "FingerPrintScanner/fxISO_Interchange.h"

class FINGERPRINTSCANNERDLLSHARED_EXPORT FingerPrintScanner
{

public:
    FingerPrintScanner();
    QString FingerPrintScanner::openFileChooser();
    char *FingerPrintScanner::convertQStringtoCharPointer(QString pathTotFolder);
    char *FingerPrintScanner::incrementFileName(QString pathTotFolder, int i);
    void FingerPrintScanner::inicializeScanner();
    int FingerPrintScanner::runTheScanner();
    int FingerPrintScanner::saveCapturedFinger(char *path);
    int FingerPrintScanner::saveCapturedFingerIntoBuffer();
    unsigned char *FingerPrintScanner::getBuffer();
    void FingerPrintScanner::deinicializeScanner();

private:
    FxBuffer gImage;
    BYTE *buffer;
    float imageQuality;
    char * afterConversionChar;
    int err;
};

#endif // FINGERPRINTSCANNER_H
