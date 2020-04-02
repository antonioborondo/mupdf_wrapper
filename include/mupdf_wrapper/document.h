#pragma once

#include <filesystem>

struct fz_document_s;
typedef struct fz_document_s fz_document;

namespace mupdf_wrapper
{
    class Context;

    class Document
    {
        fz_document* m_mupdf_document;
        const Context& m_context;

    public:
        Document(const Context& context, const std::filesystem::path& filename);
        ~Document();
        fz_document* get() const;
        int get_total_pages() const;
    };
}
