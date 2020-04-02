#include "pixmap.h"

#include "context.h"
#include "matrix.h"
#include "page.h"

#include <mupdf/fitz.h>

#include <stdexcept>

namespace mupdf_wrapper
{
    Pixmap::Pixmap(const Context& context, const Matrix& matrix, const Page& page)
        : m_context{context}
    {
        fz_try(context.get())
            m_mupdf_pixmap = fz_new_pixmap_from_page(m_context.get(), page.get(), matrix.get(), fz_device_rgb(m_context.get()), 0);
        fz_catch(m_context.get())
        {
            throw std::runtime_error("Cannot create pixmap from page");
        }
    }

    Pixmap::~Pixmap()
    {
        fz_drop_pixmap(m_context.get(), m_mupdf_pixmap);
    }

    fz_pixmap* Pixmap::get() const
    {
        return m_mupdf_pixmap;
    }

    unsigned char* Pixmap::get_samples() const
    {
        return fz_pixmap_samples(m_context.get(), m_mupdf_pixmap);
    }

    unsigned char Pixmap::get_n() const
    {
        return m_mupdf_pixmap->n;
    }

    ptrdiff_t Pixmap::get_stride() const
    {
        return m_mupdf_pixmap->stride;
    }

    int Pixmap::get_width() const
    {
        return fz_pixmap_width(m_context.get(), m_mupdf_pixmap);
    }

    int Pixmap::get_height() const
    {
        return fz_pixmap_height(m_context.get(), m_mupdf_pixmap);
    }
}
