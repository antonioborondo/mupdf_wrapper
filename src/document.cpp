#include "document.h"

#include "context.h"

#include <stdexcept>

namespace mupdf_wrapper
{
    Document::Document(Context* context, const std::string& filename)
        : m_mupdf_document(nullptr)
        , m_context(context)
    {
        fz_try(m_context->get())
            m_mupdf_document = fz_open_document(m_context->get(), filename.c_str());
        fz_catch(m_context->get())
        {
            throw std::runtime_error("Cannot open document");
        }
    }

    Document::~Document()
    {
        if(nullptr != m_mupdf_document)
        {
            fz_drop_document(m_context->get(), m_mupdf_document);
            m_mupdf_document = nullptr;
        }
    }

    fz_document* Document::get() const
    {
        return m_mupdf_document;
    }

    int Document::get_total_pages() const
    {
        auto total_pages = 0;

        fz_try(m_context->get())
            total_pages = fz_count_pages(m_context->get(), m_mupdf_document);
        fz_catch(m_context->get())
        {
            throw std::runtime_error("Cannot get total number of pages");
        }

        return total_pages;
    }
}
