#pragma once

#include <cstddef>

struct fz_pixmap_s;
typedef struct fz_pixmap_s fz_pixmap;

namespace mupdf_wrapper
{
    class Context;
    class Matrix;
    class Page;

    class Pixmap
    {
        fz_pixmap* m_mupdf_pixmap;
        const Context& m_context;

    public:
        Pixmap(const Context& context, const Matrix& matrix, const Page& page);
        ~Pixmap();
        fz_pixmap* get() const;
        unsigned char* get_samples() const;
        unsigned char get_n() const;
        ptrdiff_t get_stride() const;
        int get_width() const;
        int get_height() const;
    };
}
