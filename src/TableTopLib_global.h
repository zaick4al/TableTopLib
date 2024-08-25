#ifndef TABLETOPLIB_GLOBAL_H
#define TABLETOPLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TABLETOPLIB_LIBRARY)
#  define TABLETOPLIB_EXPORT Q_DECL_EXPORT
#else
#  define TABLETOPLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // TABLETOPLIB_GLOBAL_H
