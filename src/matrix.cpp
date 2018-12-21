#include "matrix.h"

#include <mupdf/fitz.h>

namespace mupdf_wrapper
{
    Matrix::Matrix()
        : m_mupdf_matrix(std::make_unique<fz_matrix>())
    {}

    Matrix::~Matrix()
    {}

    const fz_matrix* Matrix::get() const
    {
        return m_mupdf_matrix.get();
    }

    float Matrix::get_element_value(Element element) const
    {
        float value = 0;

        switch(element)
        {
            case Element::a:
                value = m_mupdf_matrix->a;
                break;
            case Element::b:
                value = m_mupdf_matrix->b;
                break;
            case Element::c:
                value = m_mupdf_matrix->c;
                break;
            case Element::d:
                value = m_mupdf_matrix->d;
                break;
            case Element::e:
                value = m_mupdf_matrix->e;
                break;
            case Element::f:
                value = m_mupdf_matrix->f;
                break;
        }

        return value;
    }

    void Matrix::set_zoom(unsigned int zoom) const
    {
        fz_scale(m_mupdf_matrix.get(), zoom/100.f, zoom/100.f);
    }

    void Matrix::set_rotation(float rotation) const
    {
        fz_rotate(m_mupdf_matrix.get(), rotation);
    }
}
