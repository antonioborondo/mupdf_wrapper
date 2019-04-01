#ifndef MUPDF_WRAPPER_PIXMAP_H
#define MUPDF_WRAPPER_PIXMAP_H

#include "mupdf_wrapper.h"

#include <memory>
#include <stddef.h>

struct fz_pixmap_s;
typedef struct fz_pixmap_s fz_pixmap;

namespace mupdf_wrapper
{
    class Context;
    class Document;
    class Matrix;
    class Page;

    class MUPDF_WRAPPER_API Pixmap
    {
        std::unique_ptr<fz_pixmap> m_mupdf_pixmap;
        std::shared_ptr<Context> m_context;

    public:
        Pixmap(std::shared_ptr<Context> context, std::shared_ptr<Matrix> matrix, std::shared_ptr<Page> page);
        ~Pixmap();
        fz_pixmap* get() const;
        unsigned char* get_samples() const;
        unsigned char get_n() const;
        ptrdiff_t get_stride() const;
        int get_width() const;
        int get_height() const;
    };
}

#endif
