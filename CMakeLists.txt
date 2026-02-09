cmake_minimum_required(VERSION 3.21)
project(projet_cfr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia)

add_subdirectory(src/core)
add_subdirectory(src/services)
add_subdirectory(src/app)
