cmake_minimum_required(VERSION 3.12)
project(hill_cipher)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hill_cipher
        decrypt.h
        encrypt.h
        main.cpp
        matrix.h
        mod26.h)
