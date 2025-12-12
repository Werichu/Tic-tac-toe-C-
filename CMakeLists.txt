cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

include_directories(include_files)

add_executable(tictactoe
    src/Main.cpp
)

