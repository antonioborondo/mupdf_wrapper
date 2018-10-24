#ifndef MUPDF_WRAPPER_H
#define MUPDF_WRAPPER_H

    #if defined(_MSC_VER)
        #define EXPORT_LIBRARY __declspec(dllexport)
        #define IMPORT_LIBRARY __declspec(dllimport)
    #elif defined(__GNUC__)
        #define EXPORT_LIBRARY __attribute__((visibility("default")))
        #define IMPORT_LIBRARY
    #else
        #define EXPORT_LIBRARY
        #define IMPORT_LIBRARY
    #endif

    #if defined(MUPDF_WRAPPER)
        #define MUPDF_WRAPPER_API EXPORT_LIBRARY
    #else
        #define MUPDF_WRAPPER_API IMPORT_LIBRARY
    #endif

#endif
