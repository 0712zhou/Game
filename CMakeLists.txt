cmake_minimum_required(VERSION 3.22)
project(Game C)

set(CMAKE_C_STANDARD 23)

add_executable(Game main.c game.c game.h)
