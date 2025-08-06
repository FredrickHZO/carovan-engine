cmake_minimum_required(VERSION 3.31)
project(Carovan VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build.")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

add_subdirectory(engine)
add_executable(Carovan main.cpp Sandbox.h)
target_link_libraries(Carovan PRIVATE Carovan_dependencies)
target_include_directories(Carovan PRIVATE ${CMAKE_SOURCE_DIR}/engine)
file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})
