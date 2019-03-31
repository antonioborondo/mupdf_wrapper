#include "pixmap.h"

#include "context.h"
#include "document.h"
#include "matrix.h"
#include "page.h"

#include <mupdf/fitz.h>

#include <stdexcept>

namespace mupdf_wrapper
{
    Pixmap::Pixmap(std::shared_ptr<Context> context, std::shared_ptr<Matrix> matrix, std::shared_ptr<Page> page)
        : m_context(context)
    {
        fz_try(context->get())
            m_mupdf_pixmap = std::make_unique<fz_pixmap>(*fz_new_pixmap_from_page(m_context->get(), page->get(), matrix->get(), fz_device_rgb(m_context->get()), 0));
        fz_catch(m_context->get())
        {
            throw std::runtime_error("Cannot create pixmap from page");
        }
    }

    Pixmap::~Pixmap()
    {
        fz_drop_pixmap(m_context->get(), m_mupdf_pixmap.release());
    }

    fz_pixmap* Pixmap::get() const
    {
        return m_mupdf_pixmap.get();
    }

    unsigned char* Pixmap::get_samples() const
    {
        return fz_pixmap_samples(m_context->get(), m_mupdf_pixmap.get());
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
        return fz_pixmap_width(m_context->get(), m_mupdf_pixmap.get());
    }

    int Pixmap::get_height() const
    {
        return fz_pixmap_height(m_context->get(), m_mupdf_pixmap.get());
    }
}
