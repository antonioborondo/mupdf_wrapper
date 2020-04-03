# mupdf_wrapper
[![Build Status](https://travis-ci.com/antonioborondo/mupdf_wrapper.svg?branch=master)](https://travis-ci.com/antonioborondo/mupdf_wrapper)

## Description
C++ wrapper for MuPDF.

## Features
- MuPDF fully integrated in CMake as an external project.
- MuPDF wrapped in C++ using the RAII technique.
- BDD unit tests implemented with Catch2.
- Packages managed with Conan.
- CI implemented with Travis CI.

## Libraries
- Catch2: https://www.github.com/catchorg/Catch2
- Clara: https://github.com/catchorg/Clara
- MuPDF: https://www.mupdf.com

## Tools
- CMake: https://www.cmake.org
- Conan: https://www.conan.io
- Travis CI: https://www.travis-ci.com

## How to build
### Windows (MinGW 64-bit)
1. Install MSYS2 x86_64: https://www.msys2.org
1. Run `mingw64.exe`
1. Install packages:
    ```
    pacman -S git make mingw-w64-x86_64-cmake mingw-w64-x86_64-gcc mingw-w64-x86_64-make mingw-w64-x86_64-python-pip
    ```
1. Install and configure Conan:
    ```
    pip install conan
    conan remote add catchorg https://api.bintray.com/conan/catchorg/Catch2
    ```
1. Clone repository.
1. Configure, build and test project:
    ```
    mkdir build
    cd build
    cmake -G "MinGW Makefiles" -DCMAKE_SH=CMAKE_SH-NOTFOUND -DCMAKE_BUILD_TYPE=Release -DMUPDF_WRAPPER_ENABLE_TEST=ON ../
    cmake --build .
    ctest --verbose
    ```
