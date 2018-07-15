QT -= core

TARGET = mupdf_wrapper
TEMPLATE = lib

DEFINES += MUPDF_WRAPPER

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    include/mupdf_wrapper/context.h \
    include/mupdf_wrapper/document.h \
    include/mupdf_wrapper/matrix.h \
    include/mupdf_wrapper/mupdf_wrapper.h \
    include/mupdf_wrapper/pixmap.h

SOURCES += \
    src/context.cpp \
    src/document.cpp \
    src/matrix.cpp \
    src/pixmap.cpp

INCLUDEPATH += $$PWD/include/mupdf_wrapper

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/mupdf/build/release/ -lmupdf -lmupdfthird
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/mupdf/build/debug/ -lmupdf -lmupdfthird
else:unix: LIBS += -L$$PWD/../../lib/mupdf/build/ -lmupdf -lmupdfthird

INCLUDEPATH += $$PWD/../../lib/mupdf/include
DEPENDPATH += $$PWD/../../lib/mupdf/include
