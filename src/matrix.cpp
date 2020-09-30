#include "mupdf_wrapper/matrix.h"

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    Matrix::Matrix()
        : m_mupdf_matrix{}
    {}

    const fz_matrix* Matrix::get() const
    {
        return &m_mupdf_matrix;
    }

    float Matrix::get_element_value(Element element) const
    {
        float value{};

        switch(element)
        {
            case Element::a:
                value = m_mupdf_matrix.a;
                break;
            case Element::b:
                value = m_mupdf_matrix.b;
                break;
            case Element::c:
                value = m_mupdf_matrix.c;
                break;
            case Element::d:
                value = m_mupdf_matrix.d;
                break;
            case Element::e:
                value = m_mupdf_matrix.e;
                break;
            case Element::f:
                value = m_mupdf_matrix.f;
                break;
        }

        return value;
    }

    void Matrix::set_zoom(unsigned int zoom)
    {
        fz_scale(&m_mupdf_matrix, zoom/100.f, zoom/100.f);
    }

    void Matrix::set_rotation(float rotation)
    {
        fz_rotate(&m_mupdf_matrix, rotation);
    }
}
