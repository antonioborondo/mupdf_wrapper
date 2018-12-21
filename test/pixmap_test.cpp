#include <mupdf_wrapper/context.h>
#include <mupdf_wrapper/document.h>
#include <mupdf_wrapper/matrix.h>
#include <mupdf_wrapper/page.h>
#include <mupdf_wrapper/pixmap.h>

#include <catch2/catch.hpp>

#include <memory>

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

SCENARIO("Create Pixmap from page number", "[Pixmap]")
{
    GIVEN("One page empty document")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, "test_files/one_page_empty_document.pdf");
        CHECK(document->get_total_pages() == 1);

        const auto matrix = std::make_shared<mupdf_wrapper::Matrix>();
        matrix->set_zoom(100);
        matrix->set_rotation(0);

        WHEN("Create Pixmap from negative page number")
        {
            THEN("An exception is thrown")
            {
                REQUIRE_THROWS_AS(mupdf_wrapper::Pixmap(context, document, matrix, -1), std::runtime_error);
            }
        }
        WHEN("Create Pixmap from unexisting page number")
        {
            THEN("An exception is thrown")
            {
                REQUIRE_THROWS_AS(mupdf_wrapper::Pixmap(context, document, matrix, 1), std::runtime_error);
            }
        }
        WHEN("Create Pixmap from existing page number")
        {
            THEN("No exception is thrown")
            {
                std::shared_ptr<mupdf_wrapper::Pixmap> pixmap;
                REQUIRE_NOTHROW(pixmap = std::make_shared<mupdf_wrapper::Pixmap>(context, document, matrix, 0));

                AND_THEN("Pixmap is created")
                {
                    const auto mupdf_pixmap = pixmap->get();
                    REQUIRE(nullptr != mupdf_pixmap);
                }
            }
        }     
    }
}

SCENARIO("Create empty Pixmap from empty page", "[Pixmap]")
{
    GIVEN("One page empty document")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, "test_files/one_page_empty_document.pdf");
        CHECK(document->get_total_pages() == 1);

        const auto matrix = std::make_shared<mupdf_wrapper::Matrix>();
        matrix->set_zoom(100);
        matrix->set_rotation(0);

        WHEN("Create Pixmap from empty page")
        {
            const mupdf_wrapper::Pixmap pixmap(context, document, matrix, 0);

            THEN("Pixmap is empty")
            {
                REQUIRE(is_pixmap_empty(pixmap));
            }
        }
    }
}

SCENARIO("Create not empty Pixmap from not empty page", "[Pixmap]")
{
    GIVEN("One page not empty document")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, "test_files/one_page_not_empty_document.pdf");
        CHECK(document->get_total_pages() == 1);

        const auto matrix = std::make_shared<mupdf_wrapper::Matrix>();
        matrix->set_zoom(100);
        matrix->set_rotation(0);

        WHEN("Create Pixmap from empty page")
        {
            const mupdf_wrapper::Pixmap pixmap(context, document, matrix, 0);

            THEN("Pixmap is not empty")
            {
                REQUIRE_FALSE(is_pixmap_empty(pixmap));
            }
        }
    }
}
