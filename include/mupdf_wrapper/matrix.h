#ifndef MUPDF_WRAPPER_MATRIX_H
#define MUPDF_WRAPPER_MATRIX_H

#include "mupdf_wrapper.h"

#include <memory>

struct fz_matrix_s;
typedef struct fz_matrix_s fz_matrix;

namespace mupdf_wrapper
{
    class MUPDF_WRAPPER_API Matrix
    {
        std::unique_ptr<fz_matrix> m_mupdf_matrix;

    public:
        enum class Element{a, b, c, d, e, f};

        Matrix();
        ~Matrix();
        const fz_matrix* get() const;
        float get_element_value(Element element) const;
        void set_zoom(unsigned int zoom) const;
        void set_rotation(float rotation) const;
    };
}

#endif
