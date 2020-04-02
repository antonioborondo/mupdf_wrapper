#include "document.h"

#include "context.h"

#include <mupdf/fitz.h>

#include <stdexcept>

namespace mupdf_wrapper
{
    Document::Document(const Context& context, const std::filesystem::path& filename)
        : m_context{context}
    {
        fz_try(m_context.get())
            m_mupdf_document = fz_open_document(m_context.get(), filename.string().c_str());
        fz_catch(m_context.get())
        {
            throw std::runtime_error("Cannot open document");
        }
    }

    Document::~Document()
    {
        fz_drop_document(m_context.get(), m_mupdf_document);
    }

    fz_document* Document::get() const
    {
        return m_mupdf_document;
    }

    int Document::get_total_pages() const
    {
        int total_pages{};

        fz_try(m_context.get())
            total_pages = fz_count_pages(m_context.get(), m_mupdf_document);
        fz_catch(m_context.get())
        {
            throw std::runtime_error("Cannot get total number of pages");
        }

        return total_pages;
    }
}
