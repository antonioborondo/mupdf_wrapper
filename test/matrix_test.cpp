#include <mupdf_wrapper/matrix.h>

#include <catch2/catch.hpp>

SCENARIO("Create Matrix", "[Matrix]")
{
    WHEN("Create Matrix")
    {
        const mupdf_wrapper::Matrix matrix;

        THEN("Matrix is created")
        {
            const auto mupdf_matrix = matrix.get();
            REQUIRE(nullptr != mupdf_matrix);
        }
    }
}

SCENARIO("Set Matrix zoom", "[Matrix]")
{
    GIVEN("Matrix")
    {
        mupdf_wrapper::Matrix matrix;

        WHEN("Set zoom to 0%")
        {
            matrix.set_zoom(0);

            THEN("Zoom is 0%")
            {
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::a) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::b) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::c) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::d) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::e) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::f) == Approx(0));
            }
        }
        WHEN("Set zoom to 50%")
        {
            matrix.set_zoom(50);

            THEN("Zoom is 50%")
            {
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::a) == Approx(0.5));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::b) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::c) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::d) == Approx(0.5));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::e) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::f) == Approx(0));
            }
        }
        WHEN("Set zoom to 100%")
        {
            matrix.set_zoom(100);

            THEN("Zoom is 100%")
            {
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::a) == Approx(1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::b) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::c) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::d) == Approx(1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::e) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::f) == Approx(0));
            }
        }
        WHEN("Set zoom to 150%")
        {
            matrix.set_zoom(150);

            THEN("Zoom is 150%")
            {
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::a) == Approx(1.5));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::b) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::c) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::d) == Approx(1.5));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::e) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::f) == Approx(0));
            }
        }
        WHEN("Set zoom to 200%")
        {
            matrix.set_zoom(200);

            THEN("Zoom is 200%")
            {
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::a) == Approx(2));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::b) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::c) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::d) == Approx(2));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::e) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::f) == Approx(0));
            }
        }
    }
}

SCENARIO("Set Matrix rotation", "[Matrix]")
{
    GIVEN("Matrix")
    {
        mupdf_wrapper::Matrix matrix;

        WHEN("Set rotation to 0º")
        {
            matrix.set_rotation(0);

            THEN("Rotation is 0º")
            {
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::a) == Approx(1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::b) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::c) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::d) == Approx(1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::e) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::f) == Approx(0));
            }
        }
        WHEN("Set rotation to 90º")
        {
            matrix.set_rotation(90);

            THEN("Rotation is 90º")
            {
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::a) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::b) == Approx(1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::c) == Approx(-1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::d) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::e) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::f) == Approx(0));
            }
        }
        WHEN("Set rotation to 180º")
        {
            matrix.set_rotation(180);

            THEN("Rotation is 180º")
            {
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::a) == Approx(-1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::b) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::c) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::d) == Approx(-1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::e) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::f) == Approx(0));
            }
        }
        WHEN("Set rotation to 270º")
        {
            matrix.set_rotation(270);

            THEN("Rotation is 270º")
            {
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::a) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::b) == Approx(-1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::c) == Approx(1));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::d) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::e) == Approx(0));
                CHECK(matrix.get_element_value(mupdf_wrapper::Matrix::Element::f) == Approx(0));
            }
        }
    }
}
