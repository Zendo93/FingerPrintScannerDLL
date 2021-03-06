#include "fingerprintscanner.h"
#include <QString>
#include <QByteArray>
#include <QFileDialog>
#include "FingerPrintScanner/fxISOdll.h"
#include "FingerPrintScanner/fxISOenrdlg.h"
#include "stdio.h"
#include <iostream>
using namespace  std;
#pragma comment(lib,"user32.lib")

FingerPrintScanner::FingerPrintScanner()
{
    err=0;
}
QString FingerPrintScanner::openFileChooser()
{
    QString pathTotFolder = QFileDialog::getExistingDirectory(NULL,QObject::tr("Choose folder"), NULL, NULL);
    return pathTotFolder;
}
char *FingerPrintScanner::convertQStringtoCharPointer(QString pathTotFolder)
{
    QString pathTotFolderWithSavedFile = pathTotFolder + "/finger.bmp";
    string ba = pathTotFolderWithSavedFile.toStdString();
    afterConversionChar = new char[ba.length() + 1];
    strcpy(afterConversionChar, ba.c_str());
    return afterConversionChar;
}

char *FingerPrintScanner::incrementFileName(QString pathTotFolder, int i)
{
    QString pathTotFolderWithSavedFile = pathTotFolder + "/finger" + QString::number(i) + ".bmp";
    string ba = pathTotFolderWithSavedFile.toStdString();
    afterConversionChar = new char[ba.length() + 1];
    strcpy(afterConversionChar, ba.c_str());
    return afterConversionChar;
}

void FingerPrintScanner::inicializeScanner()
{
    FxISO_Init();
    FxISO_Mem_NewBuffer(&gImage);
}

int FingerPrintScanner::runTheScanner()
{
    err = FxISO_Fing_AcquireSupervised(NULL, -1, -1, &imageQuality);
    return err;
}

int FingerPrintScanner::saveCapturedFinger(char *path)
{
    FxISO_Fing_SaveToMemory(&gImage, NATIVE_RESOLUTION, NULL);
    err = FxISO_Mem_SaveBufferToFile(path, &gImage);
    return err;
}

int FingerPrintScanner::saveCapturedFingerIntoBuffer(){
    err = FxISO_Fing_SaveToMemory(&gImage,NATIVE_RESOLUTION,NULL);
    cout << "FxBuffer size: " << gImage.sizeUsed << endl;
    if (!err)
    {
        buffer = (unsigned char *) malloc(gImage.sizeUsed*sizeof(unsigned char));
        err = FxISO_Mem_CopyBufferToArray(&gImage,buffer,gImage.sizeUsed);
    }
    else
    {
        buffer = NULL;
        err = 1;
    }
    return err;
}

unsigned char *FingerPrintScanner::getBuffer(){
    return buffer;
}

void FingerPrintScanner::deinicializeScanner()
{
    afterConversionChar = NULL;
    delete afterConversionChar;
    FxISO_Mem_DeleteBuffer(&gImage);
    FxISO_End();
}
