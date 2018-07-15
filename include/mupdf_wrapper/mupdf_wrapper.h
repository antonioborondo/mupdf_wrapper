#ifndef MUPDF_WRAPPER_H
#define MUPDF_WRAPPER_H

#include <QtCore/qglobal.h>

#if defined(MUPDF_WRAPPER)
#  define MUPDF_WRAPPER_EXPORT Q_DECL_EXPORT
#else
#  define MUPDF_WRAPPER_EXPORT Q_DECL_IMPORT
#endif

#endif
