cmake_minimum_required(VERSION 3.21)
project(woman_pong)
set(CMAKE_C_STANDARD 18)
set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

add_compile_options(-std=c++20 -g -Wall -Wextra -Wpedantic -Werror)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(libwoman_pong STATIC
  ${CMAKE_SOURCE_DIR}/src/constructor.cxx
  ${CMAKE_SOURCE_DIR}/src/extras.cxx
  ${CMAKE_SOURCE_DIR}/src/f2i.cxx
  ${CMAKE_SOURCE_DIR}/src/getDisplay.cxx
  ${CMAKE_SOURCE_DIR}/src/handlers.cxx
  ${CMAKE_SOURCE_DIR}/src/mainProc.cxx
  ${CMAKE_SOURCE_DIR}/src/processInput.cxx
  ${CMAKE_SOURCE_DIR}/src/render.cxx
  ${CMAKE_SOURCE_DIR}/src/scaling.cxx
  ${CMAKE_SOURCE_DIR}/src/update.cxx
)

add_executable(woman_pong ${CMAKE_SOURCE_DIR}/src/main.cxx)
target_link_libraries(woman_pong PRIVATE libwoman_pong -lSDL2 -lSDL2_ttf -lSDL2_image -lX11)

set_target_properties(woman_pong PROPERTIES
  LINK_FLAGS "-Wl,-rpath=lib/"
)

set_target_properties(libwoman_pong PROPERTIES
  OUTPUT_NAME woman_pong
)


