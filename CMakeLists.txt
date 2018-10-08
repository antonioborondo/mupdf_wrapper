project(mupdf_wrapper)

find_package(Qt5Core REQUIRED)

set(HEADER_FILES
    include/mupdf_wrapper/context.h
    include/mupdf_wrapper/document.h
    include/mupdf_wrapper/matrix.h
    include/mupdf_wrapper/mupdf_wrapper.h
    include/mupdf_wrapper/pixmap.h
)

set(SOURCE_FILES
    src/context.cpp
    src/document.cpp
    src/matrix.cpp
    src/pixmap.cpp
)

add_library(mupdf_wrapper SHARED
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

add_definitions(
    -DQT_DEPRECATED_WARNINGS
    -DMUPDF_WRAPPER
)

set_property(TARGET mupdf_wrapper APPEND PROPERTY
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(mupdf_wrapper
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/mupdf_wrapper
    PUBLIC
    ${CMAKE_SOURCE_DIR}/lib/mupdf/include
)

target_link_libraries(mupdf_wrapper
    PUBLIC
    debug ${CMAKE_SOURCE_DIR}/lib/mupdf/build/debug/libmupdf.a
    debug ${CMAKE_SOURCE_DIR}/lib/mupdf/build/debug/libmupdfthird.a
    optimized ${CMAKE_SOURCE_DIR}/lib/mupdf/build/release/libmupdf.a
    optimized ${CMAKE_SOURCE_DIR}/lib/mupdf/build/release/libmupdfthird.a
    Qt5::Core
)
