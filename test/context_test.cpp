#include <mupdf_wrapper/context.h>

#include <catch2/catch.hpp>

#include <memory>

TEST_CASE("Create Context", "[context]")
{
    std::unique_ptr<mupdf_wrapper::Context> context;

    REQUIRE_NOTHROW(context = std::make_unique<mupdf_wrapper::Context>());

    const auto mupdf_context = context->get();
    REQUIRE(nullptr != mupdf_context);
}

TEST_CASE("Create Context and register document handlers", "[context]")
{
    const mupdf_wrapper::Context context;

    REQUIRE_NOTHROW(context.register_document_handlers());
}
