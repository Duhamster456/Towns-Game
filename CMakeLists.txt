cmake_minimum_required(VERSION 3.16)

project(lab1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_compile_options(--coverage)
add_link_options(--coverage)

add_library(towns_game ./src/towns_game_lib/towns_game_extra.cpp ./src/towns_game_lib/towns_game.cpp)
add_library(dialogue ./src/dialogue_program/dialogue.cpp)
add_library(c_dialogue ./src/dialogue_program/c_dialogue.cpp)

add_executable(lab1 ./src/dialogue_program/main.cpp)
add_executable(lab1_cstr ./src/dialogue_program/main.cpp)

target_link_libraries(lab1 dialogue towns_game)
target_link_libraries(lab1_cstr c_dialogue towns_game)

add_subdirectory(./Catch2)
add_executable(tests ./src/testing/test.cpp)
target_link_libraries(tests PRIVATE dialogue towns_game Catch2::Catch2WithMain)