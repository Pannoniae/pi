cmake_minimum_required(VERSION 3.23)
project(pi C)

set(CMAKE_C_STANDARD 23)

add_executable(pi main.c)

find_package(PkgConfig REQUIRED)
pkg_check_modules(gmp REQUIRED IMPORTED_TARGET gmp)
target_link_libraries(pi PkgConfig::gmp)

