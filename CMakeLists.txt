cmake_minimum_required(VERSION 3.5)

project(CurvesApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)

add_executable(CurvesApp main.cpp)
target_link_libraries(CurvesApp CurvesLib)
target_include_directories(CurvesApp PRIVATE lib/src)

install(TARGETS CurvesApp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
