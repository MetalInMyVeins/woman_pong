cmake_minimum_required(VERSION 3.21.2)
project(woman_pong)
set(CMAKE_CXX_STANDARD 20)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

file(GLOB library_sources "src/*.cxx")
file(GLOB library_headers "include/*.hxx")

include_directories(${CMAKE_SOURCE_DIR}/include "/usr/include/SDL2")
set(includes ${library_headers})

add_executable(woman_pong "tests/main.cxx" ${includes})
target_compile_options(woman_pong PRIVATE -std=c++20 -Wall -Wextra -Wpedantic -Werror -I/usr/include/SDL2)

add_library(woman_ponglib SHARED ${library_sources})
target_link_libraries(woman_pong woman_ponglib -lSDL2main -lSDL2_image -lSDL2_ttf -lX11 -static-libgcc -static-libstdc++)


