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
- Catch2: https://github.com/catchorg/Catch2
- Clara: https://github.com/catchorg/Clara
- MuPDF: https://mupdf.com

## Tools
- CMake: https://cmake.org
- Conan: https://conan.io
- Travis CI: https://travis-ci.com

## How to build
### Windows (MinGW 64-bit)
1. Install MSYS2 x86_64: https://www.msys2.org
1. Open "MSYS2 MinGW 64-bit".
1. Install packages:
    ```
    pacman -S git make mingw-w64-x86_64-cmake mingw-w64-x86_64-gcc mingw-w64-x86_64-make mingw-w64-x86_64-python-pip
    ```
1. Install Conan:
    ```
    pip install conan
    ```
1. Clone the repository:
    ```
    git clone git@github.com:antonioborondo/mupdf_wrapper.git && cd mupdf_wrapper
    ```
1. Configure, build and test:
    ```
    mkdir build && cd build
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DMUPDF_WRAPPER_ENABLE_TEST=ON ..
    cmake --build .
    ctest --verbose
    ```

### Linux (Ubuntu 20.04 LTS)
1. Install packages:
    ```
    sudo apt install build-essential cmake python3-pip
    ```
1. Install Conan:
    ```
    sudo pip3 install conan
    ```
1. Clone the repository:
    ```
    git clone git@github.com:antonioborondo/mupdf_wrapper.git && cd mupdf_wrapper
    ```
1. Configure, build and test:
    ```
    mkdir build && cd build
    cmake -DCMAKE_BUILD_TYPE=Release -DMUPDF_WRAPPER_ENABLE_TEST=ON ..
    cmake --build .
    ctest --verbose
    ```
