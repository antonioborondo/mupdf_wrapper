#include <mupdf_wrapper/matrix.h>

#include <catch2/catch.hpp>

TEST_CASE("Create Matrix", "[matrix]")
{
    const mupdf_wrapper::Matrix matrix;

    const auto mupdf_matrix = matrix.get();

    REQUIRE(nullptr != mupdf_matrix);
}
