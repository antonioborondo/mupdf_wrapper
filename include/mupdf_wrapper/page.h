#ifndef MUPDF_WRAPPER_PAGE_H
#define MUPDF_WRAPPER_PAGE_H

#include "mupdf_wrapper.h"

#include <memory>

struct fz_page_s;
typedef struct fz_page_s fz_page;

namespace mupdf_wrapper
{
    class Context;
    class Document;

    class MUPDF_WRAPPER_API Page
    {
        fz_page* m_mupdf_page;
        std::shared_ptr<Context> m_context;

    public:
        Page(std::shared_ptr<Context> context, std::shared_ptr<Document> document, int page_number);
        ~Page();
        fz_page* get() const;
    };
}

#endif
