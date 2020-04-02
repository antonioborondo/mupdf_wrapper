#pragma once

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    class Matrix
    {
        fz_matrix m_mupdf_matrix;

    public:
        enum class Element{a, b, c, d, e, f};

        Matrix();
        const fz_matrix* get() const;
        float get_element_value(Element element) const;
        void set_zoom(unsigned int zoom);
        void set_rotation(float rotation);
    };
}
