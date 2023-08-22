cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME CurvesApp)
set(LIBRARY_NAME CurvesLib)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES src/main.cpp)

project(${PROJECT_NAME} LANGUAGES CXX)

add_subdirectory(lib)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME})
target_include_directories(${PROJECT_NAME} PRIVATE lib/src)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
