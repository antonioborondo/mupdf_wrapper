#include <mupdf_wrapper/context.h>
#include <mupdf_wrapper/document.h>

#include <catch2/catch.hpp>

#include <memory>

TEST_CASE("GIVEN no document WHEN create new Document THEN an exception is thrown", "[document]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();
    context->register_document_handlers();

    REQUIRE_THROWS_AS(mupdf_wrapper::Document(context, ""), std::runtime_error);
}

TEST_CASE("GIVEN one page empty document WHEN create new Document THEN Document is created without throwing exception", "[document]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();
    context->register_document_handlers();

    std::shared_ptr<mupdf_wrapper::Document> document;
    REQUIRE_NOTHROW(document = std::make_shared<mupdf_wrapper::Document>(context, "test_files/one_page_empty_document.pdf"));

    const auto mupdf_document = document->get();
    REQUIRE(nullptr != mupdf_document);
}

TEST_CASE("GIVEN one page empty document WHEN create new Document without register document handlers THEN an exception is thrown", "[document]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();

    REQUIRE_THROWS_AS(mupdf_wrapper::Document(context, "one_page_empty_document.pdf"), std::runtime_error);
}

TEST_CASE("GIVEN one page empty document WHEN get total pages THEN total pages equal to 1", "[document]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();
    context->register_document_handlers();

    const auto document = std::make_shared<mupdf_wrapper::Document>(context, "test_files/one_page_empty_document.pdf");
    REQUIRE(document->get_total_pages() == 1);
}

TEST_CASE("GIVEN five pages empty document WHEN get total pages THEN total pages equal to 5", "[document]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();
    context->register_document_handlers();

    const auto document = std::make_shared<mupdf_wrapper::Document>(context, "test_files/five_pages_empty_document.pdf");
    REQUIRE(document->get_total_pages() == 5);
}
