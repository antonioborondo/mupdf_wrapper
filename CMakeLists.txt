cmake_minimum_required(VERSION 3.16)

project(mupdf_wrapper)

set(CMAKE_CXX_STANDARD 17)

set(MUPDF_BUILD_CONFIGURATION "")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(MUPDF_BUILD_CONFIGURATION "build=debug")
endif()

include(ExternalProject)

ExternalProject_Add(mupdf
    GIT_REPOSITORY git://git.ghostscript.com/mupdf.git
    GIT_TAG 1.13.0
    GIT_SUBMODULES
    CONFIGURE_COMMAND ""
    BUILD_COMMAND make XCFLAGS=-fPIC XCFLAGS+=-w HAVE_X11=no HAVE_GLUT=no libs ${MUPDF_BUILD_CONFIGURATION}
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)

add_library(mupdf_wrapper STATIC
    include/mupdf_wrapper/context.h
    include/mupdf_wrapper/document.h
    include/mupdf_wrapper/matrix.h
    include/mupdf_wrapper/page.h
    include/mupdf_wrapper/pixmap.h
    src/context.cpp
    src/document.cpp
    src/matrix.cpp
    src/page.cpp
    src/pixmap.cpp
)

ExternalProject_Get_Property(mupdf SOURCE_DIR)

target_include_directories(mupdf_wrapper
    PUBLIC
    include
    ${SOURCE_DIR}/include
)

ExternalProject_Get_Property(mupdf BINARY_DIR)

target_link_libraries(mupdf_wrapper
    PUBLIC
    debug ${BINARY_DIR}/build/debug/libmupdf.a
    debug ${BINARY_DIR}/build/debug/libmupdfthird.a
    optimized ${BINARY_DIR}/build/release/libmupdf.a
    optimized ${BINARY_DIR}/build/release/libmupdfthird.a
)

add_dependencies(mupdf_wrapper mupdf)

option(MUPDF_WRAPPER_ENABLE_TEST "Enable test")

if(MUPDF_WRAPPER_ENABLE_TEST)

    set(CONAN_CMAKE ${CMAKE_BINARY_DIR}/conan.cmake)

    if(NOT EXISTS ${CONAN_CMAKE})
        message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
        file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake" ${CONAN_CMAKE})
    endif()

    include(${CONAN_CMAKE})

    conan_add_remote(
        NAME catchorg
        URL https://api.bintray.com/conan/catchorg/Catch2
    )

    conan_cmake_run(
        REQUIRES
        Catch2/2.11.3@catchorg/stable
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
    )

    add_executable(mupdf_wrapper_test
        test/context_test.cpp
        test/document_test.cpp
        test/main.cpp
        test/matrix_test.cpp
        test/page_test.cpp
        test/pixmap_test.cpp
    )

    target_link_libraries(mupdf_wrapper_test
        PRIVATE
        mupdf_wrapper
        CONAN_PKG::Catch2
        stdc++fs
    )

    enable_testing()

    add_test(NAME mupdf_wrapper_test COMMAND mupdf_wrapper_test --tfd ${CMAKE_SOURCE_DIR}/test_files)

endif()
