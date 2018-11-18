#include "pixmap.h"

#include "context.h"
#include "document.h"
#include "matrix.h"
#include "page.h"

#include <stdexcept>

namespace mupdf_wrapper
{
    Pixmap::Pixmap(std::shared_ptr<Context> context, std::shared_ptr<Document> document, std::shared_ptr<Matrix> matrix, int page_number)
        : m_mupdf_pixmap(nullptr)
        , m_context(context)
    {
        fz_try(context->get())
            m_mupdf_pixmap = fz_new_pixmap_from_page_number(m_context->get(), document->get(), page_number, matrix->get(), fz_device_rgb(m_context->get()), 0);
        fz_catch(m_context->get())
        {
            throw std::runtime_error("Cannot create pixmap from page number");
        }
    }

    Pixmap::Pixmap(std::shared_ptr<Context> context, std::shared_ptr<Document> document, std::shared_ptr<Matrix> matrix, std::shared_ptr<Page> page)
        : m_mupdf_pixmap(nullptr)
        , m_context(context)
    {
        fz_try(context->get())
            m_mupdf_pixmap = fz_new_pixmap_from_page(m_context->get(), page->get(), matrix->get(), fz_device_rgb(m_context->get()), 0);
        fz_catch(m_context->get())
        {
            throw std::runtime_error("Cannot create pixmap from page");
        }
    }

    Pixmap::~Pixmap()
    {
        if(nullptr != m_mupdf_pixmap)
        {
            fz_drop_pixmap(m_context->get(), m_mupdf_pixmap);
            m_mupdf_pixmap = nullptr;
        }
    }

    fz_pixmap* Pixmap::get() const
    {
        return m_mupdf_pixmap;
    }

    unsigned char* Pixmap::get_samples() const
    {
        return fz_pixmap_samples(m_context->get(), m_mupdf_pixmap);
    }

    int Pixmap::get_width() const
    {
        return fz_pixmap_width(m_context->get(), m_mupdf_pixmap);
    }

    int Pixmap::get_height() const
    {
        return fz_pixmap_height(m_context->get(), m_mupdf_pixmap);
    }
}
