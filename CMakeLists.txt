cmake_minimum_required(VERSION 3.12)

project(mupdf_wrapper)

set(CMAKE_CXX_STANDARD 17)

set(CONAN_CMAKE ${CMAKE_BINARY_DIR}/conan.cmake)

if(NOT EXISTS ${CONAN_CMAKE})
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/develop/conan.cmake" ${CONAN_CMAKE})
endif()

include(${CONAN_CMAKE})

conan_cmake_run(
    REQUIRES
    Catch2/2.11.3@catchorg/stable
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

set(MUPDF_BUILD_CONFIGURATION "")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(MUPDF_BUILD_CONFIGURATION "build=debug")
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

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

set(PUBLIC_HEADER_FILES_DIRECTORY include)
set(SOURCE_FILES_DIRECTORY src)
set(TEST_FILES_DIRECTORY test)

set(PUBLIC_HEADER_FILES
    ${PUBLIC_HEADER_FILES_DIRECTORY}/mupdf_wrapper/context.h
    ${PUBLIC_HEADER_FILES_DIRECTORY}/mupdf_wrapper/document.h
    ${PUBLIC_HEADER_FILES_DIRECTORY}/mupdf_wrapper/matrix.h
    ${PUBLIC_HEADER_FILES_DIRECTORY}/mupdf_wrapper/page.h
    ${PUBLIC_HEADER_FILES_DIRECTORY}/mupdf_wrapper/pixmap.h
)

set(SOURCE_FILES
    ${SOURCE_FILES_DIRECTORY}/context.cpp
    ${SOURCE_FILES_DIRECTORY}/document.cpp
    ${SOURCE_FILES_DIRECTORY}/matrix.cpp
    ${SOURCE_FILES_DIRECTORY}/page.cpp
    ${SOURCE_FILES_DIRECTORY}/pixmap.cpp
)

add_library(mupdf_wrapper STATIC
    ${PUBLIC_HEADER_FILES}
    ${SOURCE_FILES}
)

ExternalProject_Get_Property(mupdf SOURCE_DIR)

target_include_directories(mupdf_wrapper
    PRIVATE
    ${PUBLIC_HEADER_FILES_DIRECTORY}/mupdf_wrapper
    PUBLIC
    ${SOURCE_DIR}/include
    INTERFACE
    ${PUBLIC_HEADER_FILES_DIRECTORY}
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

set(TEST_FILES
    ${TEST_FILES_DIRECTORY}/context_test.cpp
    ${TEST_FILES_DIRECTORY}/document_test.cpp
    ${TEST_FILES_DIRECTORY}/main.cpp
    ${TEST_FILES_DIRECTORY}/matrix_test.cpp
    ${TEST_FILES_DIRECTORY}/page_test.cpp
    ${TEST_FILES_DIRECTORY}/pixmap_test.cpp
)

add_executable(mupdf_wrapper_test
    ${TEST_FILES}
)

target_link_libraries(mupdf_wrapper_test
    PRIVATE
    mupdf_wrapper
    CONAN_PKG::Catch2
    stdc++fs
)

enable_testing()

add_test(NAME mupdf_wrapper_test COMMAND mupdf_wrapper_test --tfd ${CMAKE_SOURCE_DIR}/test_files)
