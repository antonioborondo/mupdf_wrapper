#include <mupdf_wrapper/context.h>

#include <catch2/catch.hpp>

#include <memory>

TEST_CASE("GIVEN no Context WHEN create new Context THEN Context is created", "[context]")
{
    std::unique_ptr<mupdf_wrapper::Context> context;

    REQUIRE_NOTHROW(context = std::make_unique<mupdf_wrapper::Context>());

    const auto mupdf_context = context->get();
    REQUIRE(nullptr != mupdf_context);
}

TEST_CASE("GIVEN Context WHEN register document handlers THEN no exception is thrown", "[context]")
{
    const mupdf_wrapper::Context context;

    REQUIRE_NOTHROW(context.register_document_handlers());
}
