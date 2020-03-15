#include <mupdf_wrapper/context.h>
#include <mupdf_wrapper/document.h>
#include <mupdf_wrapper/page.h>

#include <catch2/catch.hpp>

#include <filesystem>
#include <memory>

extern std::filesystem::path test_files_directory;

SCENARIO("Create Page", "[Page]")
{
    GIVEN("Document")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, test_files_directory / "one_page_empty_document.pdf");
        CHECK(document->get_total_pages() == 1);

        WHEN("Create Page from existing page number")
        {
            std::unique_ptr<mupdf_wrapper::Page> page;
            REQUIRE_NOTHROW(page = std::make_unique<mupdf_wrapper::Page>(context, document, 0));

            THEN("Page is created")
            {
                const auto mupdf_page = page->get();
                REQUIRE(nullptr != mupdf_page);
            }
        }
        WHEN("Create Page from negative page number")
        {
            THEN("An exception is thrown")
            {
                REQUIRE_THROWS_AS(mupdf_wrapper::Page(context, document, -1), std::runtime_error);
            }
        }
        WHEN("Create Page from unexisting page number")
        {
            THEN("An exception is thrown")
            {
                REQUIRE_THROWS_AS(mupdf_wrapper::Page(context, document, 1), std::runtime_error);
            }
        }
    }
}
