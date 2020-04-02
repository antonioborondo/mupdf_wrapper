#include "page.h"

#include "context.h"
#include "document.h"

#include <mupdf/fitz.h>

#include <stdexcept>

namespace mupdf_wrapper
{
    Page::Page(const Context& context, const Document& document, int page_number)
        : m_context{context}
    {
        fz_try(m_context.get())
            m_mupdf_page = fz_load_page(context.get(), document.get(), page_number);
        fz_catch(m_context.get())
        {
            throw std::runtime_error("Cannot load page");
        }
    }

    Page::~Page()
    {
        fz_drop_page(m_context.get(), m_mupdf_page);
    }

    fz_page* Page::get() const
    {
        return m_mupdf_page;
    }
}
