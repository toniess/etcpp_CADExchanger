cmake_minimum_required(VERSION 3.5)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

set(HEADERS
    src/curve.h
    src/circle.h
    src/ellipse.h
    src/spiral.h
)

set(SOURCES
    src/circle.cpp
    src/ellipse.cpp
    src/spiral.cpp
)

add_library(CurvesLib SHARED ${HEADERS} ${SOURCES})
target_include_directories(CurvesLib PRIVATE src)
target_link_directories(CurvesLib PUBLIC src)
