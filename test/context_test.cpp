#include <mupdf_wrapper/context.h>

#include <catch2/catch.hpp>

#include <memory>

SCENARIO("Create Context", "[Context]")
{
    WHEN("Create Context")
    {
        THEN("No exception is thrown")
        {
            std::unique_ptr<mupdf_wrapper::Context> context;
            REQUIRE_NOTHROW(context = std::make_unique<mupdf_wrapper::Context>());

            AND_THEN("Context is created")
            {
                const auto mupdf_context = context->get();
                REQUIRE(nullptr != mupdf_context);
            }
        }
    }
}

SCENARIO("Register document handlers", "[Context]")
{
    GIVEN("Context")
    {
        mupdf_wrapper::Context context;

        WHEN("Register document handlers")
        {
            THEN("No exception is thrown")
            {
                REQUIRE_NOTHROW(context.register_document_handlers());
            }
        }
    }
}
