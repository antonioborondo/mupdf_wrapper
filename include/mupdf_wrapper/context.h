#pragma once

struct fz_context_s;
typedef struct fz_context_s fz_context;

namespace mupdf_wrapper
{
    class Context
    {
        fz_context* m_mupdf_context;

    public:
        Context();
        ~Context();
        fz_context* get() const;
        void register_document_handlers();
    };
}
