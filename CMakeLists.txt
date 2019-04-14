project(mupdf_wrapper)

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

set(PUBLIC_HEADER_FILES_FOLDER include)
set(SOURCE_FILES_FOLDER src)
set(TEST_FILES_FOLDER test)

set(PUBLIC_HEADER_FILES
    ${PUBLIC_HEADER_FILES_FOLDER}/mupdf_wrapper/context.h
    ${PUBLIC_HEADER_FILES_FOLDER}/mupdf_wrapper/document.h
    ${PUBLIC_HEADER_FILES_FOLDER}/mupdf_wrapper/matrix.h
    ${PUBLIC_HEADER_FILES_FOLDER}/mupdf_wrapper/mupdf_wrapper.h
    ${PUBLIC_HEADER_FILES_FOLDER}/mupdf_wrapper/page.h
    ${PUBLIC_HEADER_FILES_FOLDER}/mupdf_wrapper/pixmap.h
)

set(SOURCE_FILES
    ${SOURCE_FILES_FOLDER}/context.cpp
    ${SOURCE_FILES_FOLDER}/document.cpp
    ${SOURCE_FILES_FOLDER}/matrix.cpp
    ${SOURCE_FILES_FOLDER}/page.cpp
    ${SOURCE_FILES_FOLDER}/pixmap.cpp
)

add_library(mupdf_wrapper SHARED
    ${PUBLIC_HEADER_FILES}
    ${SOURCE_FILES}
)

add_definitions(
    -DMUPDF_WRAPPER
)

set_property(TARGET mupdf_wrapper APPEND PROPERTY
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include
)

ExternalProject_Get_Property(mupdf SOURCE_DIR)

target_include_directories(mupdf_wrapper
    PRIVATE
    ${PUBLIC_HEADER_FILES_FOLDER}/mupdf_wrapper
    PUBLIC
    ${SOURCE_DIR}/include
)

ExternalProject_Get_Property(mupdf BINARY_DIR)

target_link_libraries(mupdf_wrapper
    PUBLIC
    debug ${BINARY_DIR}/build/debug/libmupdf.a
    debug ${BINARY_DIR}/build/debug/libmupdfthird.a
    optimized ${BINARY_DIR}/build/release/libmupdf.a
    optimized ${BINARY_DIR}/build/release/libmupdfthird.a
    PRIVATE
    stdc++
)

add_dependencies(mupdf_wrapper mupdf)

set(TEST_FILES
    ${TEST_FILES_FOLDER}/context_test.cpp
    ${TEST_FILES_FOLDER}/document_test.cpp
    ${TEST_FILES_FOLDER}/main.cpp
    ${TEST_FILES_FOLDER}/matrix_test.cpp
    ${TEST_FILES_FOLDER}/page_test.cpp
    ${TEST_FILES_FOLDER}/pixmap_test.cpp
)

add_executable(mupdf_wrapper_test
    ${TEST_FILES}
)

target_link_libraries(mupdf_wrapper_test
    PRIVATE
    mupdf_wrapper
    catch2
)
