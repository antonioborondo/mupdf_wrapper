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
        const mupdf_wrapper::Matrix matrix;
        const auto mupdf_matrix = matrix.get();
        REQUIRE(nullptr != mupdf_matrix);

        WHEN("Set zoom to 0%")
        {
            matrix.set_zoom(0);

            THEN("Zoom is 0%")
            {
                CHECK(mupdf_matrix->a == Approx(0));
                CHECK(mupdf_matrix->b == Approx(0));
                CHECK(mupdf_matrix->c == Approx(0));
                CHECK(mupdf_matrix->d == Approx(0));
                CHECK(mupdf_matrix->e == Approx(0));
                CHECK(mupdf_matrix->f == Approx(0));
            }
        }
        WHEN("Set zoom to 50%")
        {
            matrix.set_zoom(50);

            THEN("Zoom is 50%")
            {
                CHECK(mupdf_matrix->a == Approx(0.5));
                CHECK(mupdf_matrix->b == Approx(0));
                CHECK(mupdf_matrix->c == Approx(0));
                CHECK(mupdf_matrix->d == Approx(0.5));
                CHECK(mupdf_matrix->e == Approx(0));
                CHECK(mupdf_matrix->f == Approx(0));
            }
        }
        WHEN("Set zoom to 100%")
        {
            matrix.set_zoom(100);

            THEN("Zoom is 100%")
            {
                CHECK(mupdf_matrix->a == Approx(1));
                CHECK(mupdf_matrix->b == Approx(0));
                CHECK(mupdf_matrix->c == Approx(0));
                CHECK(mupdf_matrix->d == Approx(1));
                CHECK(mupdf_matrix->e == Approx(0));
                CHECK(mupdf_matrix->f == Approx(0));
            }
        }
        WHEN("Set zoom to 150%")
        {
            matrix.set_zoom(150);

            THEN("Zoom is 150%")
            {
                CHECK(mupdf_matrix->a == Approx(1.5));
                CHECK(mupdf_matrix->b == Approx(0));
                CHECK(mupdf_matrix->c == Approx(0));
                CHECK(mupdf_matrix->d == Approx(1.5));
                CHECK(mupdf_matrix->e == Approx(0));
                CHECK(mupdf_matrix->f == Approx(0));
            }
        }
        WHEN("Set zoom to 200%")
        {
            matrix.set_zoom(200);

            THEN("Zoom is 200%")
            {
                CHECK(mupdf_matrix->a == Approx(2));
                CHECK(mupdf_matrix->b == Approx(0));
                CHECK(mupdf_matrix->c == Approx(0));
                CHECK(mupdf_matrix->d == Approx(2));
                CHECK(mupdf_matrix->e == Approx(0));
                CHECK(mupdf_matrix->f == Approx(0));
            }
        }
    }
}

SCENARIO("Set Matrix rotation", "[Matrix]")
{
    GIVEN("Matrix")
    {
        const mupdf_wrapper::Matrix matrix;
        const auto mupdf_matrix = matrix.get();
        REQUIRE(nullptr != mupdf_matrix);

        WHEN("Set rotation to 0º")
        {
            matrix.set_rotation(0);

            THEN("Rotation is 0º")
            {
                CHECK(mupdf_matrix->a == Approx(1));
                CHECK(mupdf_matrix->b == Approx(0));
                CHECK(mupdf_matrix->c == Approx(0));
                CHECK(mupdf_matrix->d == Approx(1));
                CHECK(mupdf_matrix->e == Approx(0));
                CHECK(mupdf_matrix->f == Approx(0));
            }
        }
        WHEN("Set rotation to 90º")
        {
            matrix.set_rotation(90);

            THEN("Rotation is 90º")
            {
                CHECK(mupdf_matrix->a == Approx(0));
                CHECK(mupdf_matrix->b == Approx(1));
                CHECK(mupdf_matrix->c == Approx(-1));
                CHECK(mupdf_matrix->d == Approx(0));
                CHECK(mupdf_matrix->e == Approx(0));
                CHECK(mupdf_matrix->f == Approx(0));
            }
        }
        WHEN("Set rotation to 180º")
        {
            matrix.set_rotation(180);

            THEN("Rotation is 180º")
            {
                CHECK(mupdf_matrix->a == Approx(-1));
                CHECK(mupdf_matrix->b == Approx(0));
                CHECK(mupdf_matrix->c == Approx(0));
                CHECK(mupdf_matrix->d == Approx(-1));
                CHECK(mupdf_matrix->e == Approx(0));
                CHECK(mupdf_matrix->f == Approx(0));
            }
        }
        WHEN("Set rotation to 270º")
        {
            matrix.set_rotation(270);

            THEN("Rotation is 270º")
            {
                CHECK(mupdf_matrix->a == Approx(0));
                CHECK(mupdf_matrix->b == Approx(-1));
                CHECK(mupdf_matrix->c == Approx(1));
                CHECK(mupdf_matrix->d == Approx(0));
                CHECK(mupdf_matrix->e == Approx(0));
                CHECK(mupdf_matrix->f == Approx(0));
            }
        }
    }
}
