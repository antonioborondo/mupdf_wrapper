#include "matrix.h"

namespace mupdf_wrapper
{
    Matrix::Matrix()
        : m_mupdf_matrix(std::make_unique<fz_matrix>())
    {}

    const fz_matrix* Matrix::get() const
    {
        return m_mupdf_matrix.get();
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
