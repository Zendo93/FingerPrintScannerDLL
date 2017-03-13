#ifndef FINGERPRINTSCANNERDLL_GLOBAL_H
#define FINGERPRINTSCANNERDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FINGERPRINTSCANNERDLL_LIBRARY)
#  define FINGERPRINTSCANNERDLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define FINGERPRINTSCANNERDLLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // FINGERPRINTSCANNERDLL_GLOBAL_H