#include <mupdf_wrapper/context.h>
#include <mupdf_wrapper/document.h>

#include <catch2/catch.hpp>

#include <filesystem>
#include <memory>

extern std::filesystem::path test_files_directory;

SCENARIO("Create Document", "[Document]")
{
    GIVEN("Context")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();

        WHEN("Register document handlers")
        {
            context->register_document_handlers();

            AND_WHEN("Create Document from unexisting document")
            {
                THEN("An exception is thrown")
                {
                    REQUIRE_THROWS_AS(mupdf_wrapper::Document(context, ""), std::runtime_error);
                }
            }
            AND_WHEN("Create Document from existing document")
            {
                std::unique_ptr<mupdf_wrapper::Document> document;
                REQUIRE_NOTHROW(document = std::make_unique<mupdf_wrapper::Document>(context, test_files_directory / "one_page_empty_document.pdf"));

                THEN("Document is created")
                {
                    const auto mupdf_document = document->get();
                    REQUIRE(nullptr != mupdf_document);
                }
            }
        }
        WHEN("Create Document from existing document without register document handlers first")
        {
            THEN("An exception is thrown")
            {
                REQUIRE_THROWS_AS(mupdf_wrapper::Document(context, test_files_directory / "one_page_empty_document.pdf"), std::runtime_error);
            }
        }
    }
}

SCENARIO("Get Document total pages", "[Document]")
{
    GIVEN("Context")
    {
        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        AND_GIVEN("One page document")
        {
            const auto document = std::make_unique<mupdf_wrapper::Document>(context, test_files_directory / "one_page_empty_document.pdf");

            WHEN("Get total pages")
            {
                const auto total_pages = document->get_total_pages();

                THEN("Total pages equal to one")
                {
                    REQUIRE(1 == total_pages);
                }
            }
        }
        GIVEN("Five pages document")
        {
            const auto document = std::make_shared<mupdf_wrapper::Document>(context, test_files_directory / "five_pages_empty_document.pdf");

            WHEN("Get total pages")
            {
                const auto total_pages = document->get_total_pages();

                THEN("Total pages equal to five")
                {
                    REQUIRE(5 == total_pages);
                }
            }
        }
    }
}
