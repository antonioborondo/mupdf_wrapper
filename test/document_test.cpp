#include <mupdf_wrapper/context.h>
#include <mupdf_wrapper/document.h>

#include <catch2/catch.hpp>

#include <memory>

TEST_CASE("Create Document throws exception if document handlers are not registered", "[document]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();

    REQUIRE_THROWS_AS(mupdf_wrapper::Document(context, ""), std::runtime_error);
}

TEST_CASE("Create Document throws exception if filename is empty", "[document]")
{
    const auto context = std::make_shared<mupdf_wrapper::Context>();
    context->register_document_handlers();

    REQUIRE_THROWS_AS(mupdf_wrapper::Document(context, ""), std::runtime_error);
}
