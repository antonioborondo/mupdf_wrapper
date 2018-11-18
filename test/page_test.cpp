#include <mupdf_wrapper/context.h>
#include <mupdf_wrapper/document.h>
#include <mupdf_wrapper/page.h>

#include <catch2/catch.hpp>

#include <memory>

TEST_CASE("GIVEN one page empty document WHEN create new Page from existing page number THEN Page is created without throwing exception", "[page]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();
    context->register_document_handlers();

    const auto document = std::make_shared<mupdf_wrapper::Document>(context, "one_page_empty_document.pdf");
    CHECK(document->get_total_pages() == 1);

    std::shared_ptr<mupdf_wrapper::Page> page;
    REQUIRE_NOTHROW(page = std::make_shared<mupdf_wrapper::Page>(context, document, 0));

    const auto mupdf_page = page->get();
    REQUIRE(nullptr != mupdf_page);
}

TEST_CASE("GIVEN one page empty document WHEN create new Page from negative page number THEN an exception is thrown", "[page]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();
    context->register_document_handlers();

    const auto document = std::make_shared<mupdf_wrapper::Document>(context, "one_page_empty_document.pdf");

    std::shared_ptr<mupdf_wrapper::Page> page;
    REQUIRE_THROWS_AS(page = std::make_shared<mupdf_wrapper::Page>(context, document, -1), std::runtime_error);
}

TEST_CASE("GIVEN one page empty document WHEN create new Page from unexisting page number THEN an exception is thrown", "[page]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();
    context->register_document_handlers();

    const auto document = std::make_shared<mupdf_wrapper::Document>(context, "one_page_empty_document.pdf");
    CHECK(document->get_total_pages() == 1);

    std::shared_ptr<mupdf_wrapper::Page> page;
    REQUIRE_THROWS_AS(page = std::make_shared<mupdf_wrapper::Page>(context, document, 1), std::runtime_error);
}
