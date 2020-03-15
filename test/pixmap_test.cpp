#include <mupdf_wrapper/context.h>
#include <mupdf_wrapper/document.h>
#include <mupdf_wrapper/matrix.h>
#include <mupdf_wrapper/page.h>
#include <mupdf_wrapper/pixmap.h>

#include <catch2/catch.hpp>

#include <filesystem>
#include <memory>

extern std::filesystem::path test_files_directory;

namespace
{
    bool is_pixmap_empty(const mupdf_wrapper::Pixmap& pixmap)
    {
        const auto height = pixmap.get_height();
        const auto width = pixmap.get_width();

        for(auto y = 0; y < height; y++)
        {
            auto pixel_color = &pixmap.get_samples()[y * pixmap.get_stride()];

            for(auto x = 0; x < width; x++)
            {
                if((255 != pixel_color[0]) || (255 != pixel_color[1]) || (255 != pixel_color[2]))
                {
                    return false;
                }
                pixel_color += pixmap.get_n();
            }
        }

        return true;
    }
}

SCENARIO("Create Pixmap", "[Pixmap]")
{
    GIVEN("Empty Page")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, test_files_directory / "one_page_empty_document.pdf");

        const auto page = std::make_shared<mupdf_wrapper::Page>(context, document, 0);

        const auto matrix = std::make_shared<mupdf_wrapper::Matrix>();
        matrix->set_zoom(100);
        matrix->set_rotation(0);

        WHEN("Create Pixmap")
        {
            const mupdf_wrapper::Pixmap pixmap(context, matrix, page);

            THEN("Pixmap is empty")
            {
                REQUIRE(is_pixmap_empty(pixmap));
            }
        }
    }
    GIVEN("Not empty Page")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, test_files_directory / "one_page_not_empty_document.pdf");

        const auto page = std::make_shared<mupdf_wrapper::Page>(context, document, 0);

        const auto matrix = std::make_shared<mupdf_wrapper::Matrix>();
        matrix->set_zoom(100);
        matrix->set_rotation(0);

        WHEN("Create Pixmap")
        {
            const mupdf_wrapper::Pixmap pixmap(context, matrix, page);

            THEN("Pixmap is not empty")
            {
                REQUIRE_FALSE(is_pixmap_empty(pixmap));
            }
        }
    }
}
