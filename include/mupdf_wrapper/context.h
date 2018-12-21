#ifndef MUPDF_WRAPPER_CONTEXT_H
#define MUPDF_WRAPPER_CONTEXT_H

#include "mupdf_wrapper.h"

#include <memory>

struct fz_context_s;
typedef struct fz_context_s fz_context;

namespace mupdf_wrapper
{
    class MUPDF_WRAPPER_API Context
    {
        std::unique_ptr<fz_context> m_mupdf_context;

    public:
        Context();
        ~Context();
        fz_context* get() const;
        void register_document_handlers() const;
    };
}

#endif
