#include "matrix.h"

namespace mupdf_wrapper
{
    Matrix::Matrix()
        : m_mupdf_matrix(nullptr)
    {
        m_mupdf_matrix = new fz_matrix();
    }

    Matrix::~Matrix()
    {
        delete m_mupdf_matrix;
        m_mupdf_matrix = nullptr;
    }

    const fz_matrix* Matrix::get() const
    {
        return m_mupdf_matrix;
    }

    void Matrix::set_zoom(unsigned int zoom) const
    {
        fz_scale(m_mupdf_matrix, zoom/100.f, zoom/100.f);
    }

    void Matrix::set_rotation(float rotation) const
    {
        fz_rotate(m_mupdf_matrix, rotation);
    }
}
