#pragma once

struct fz_page_s;
typedef struct fz_page_s fz_page;

namespace mupdf_wrapper
{
    class Context;
    class Document;

    class Page
    {
        fz_page* m_mupdf_page;
        const Context& m_context;

    public:
        Page(const Context& context, const Document& document, int page_number);
        ~Page();
        fz_page* get() const;
    };
}
