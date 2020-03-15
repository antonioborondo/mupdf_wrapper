#define CATCH_CONFIG_RUNNER

#include <catch2/catch.hpp>

#include <filesystem>

std::filesystem::path test_files_directory;

int main(int argc, const char** argv)
{
    Catch::Session session;

    const auto cli = session.cli()
            | Catch::clara::Opt(test_files_directory, "test_files_directory")
            ["--tfd"]
            ("test files directory")
            .required();

    session.cli(cli);

    const auto applyCommandLineResult = session.applyCommandLine(argc, argv);
    if(applyCommandLineResult != 0)
    {
        return applyCommandLineResult;
    }

    if(!std::filesystem::is_directory(test_files_directory))
    {
        std::cout << "Option --tfd has to be a valid directory" << std::endl;

        return 1;
    }

    return session.run();
}
