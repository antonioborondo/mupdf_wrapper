#include "document.h"

#include "context.h"

#include <mupdf/fitz.h>

#include <stdexcept>

namespace mupdf_wrapper
{
    Document::Document(std::shared_ptr<Context> context, const std::filesystem::path& filename)
        : m_context(context)
    {
        fz_try(m_context->get())
            m_mupdf_document = std::unique_ptr<fz_document>(fz_open_document(m_context->get(), filename.string().c_str()));
        fz_catch(m_context->get())
        {
            throw std::runtime_error("Cannot open document");
        }
    }

    Document::~Document()
    {
        fz_drop_document(m_context->get(), m_mupdf_document.release());
    }

    fz_document* Document::get() const
    {
        return m_mupdf_document.get();
    }

    int Document::get_total_pages() const
    {
        auto total_pages = 0;

        fz_try(m_context->get())
            total_pages = fz_count_pages(m_context->get(), m_mupdf_document.get());
        fz_catch(m_context->get())
        {
            throw std::runtime_error("Cannot get total number of pages");
        }

        return total_pages;
    }
}
