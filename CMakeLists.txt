cmake_minimum_required(VERSION 3.14)

project(TableTopLib LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(src/CMakeLists.txt)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(TableTopLib SHARED
    ${SOURCES_INCLUDES}
)

target_include_directories(TableTopLib PUBLIC
    ${INCLUDE_PATHS}
)

target_link_libraries(TableTopLib PRIVATE
    Qt6::Core)

target_compile_definitions(TableTopLib PRIVATE
    TABLETOPLIB_LIBRARY)
