#ifndef MUPDF_WRAPPER_DOCUMENT_H
#define MUPDF_WRAPPER_DOCUMENT_H

#include "mupdf_wrapper.h"

#include <string>

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    class Context;

    class MUPDF_WRAPPER_EXPORT Document
    {
        fz_document* m_mupdf_document;
        Context* m_context;

    public:
        Document(Context* context, const std::string& filename);
        ~Document();
        fz_document* get() const;
        int get_total_pages() const;
    };
}

#endif
