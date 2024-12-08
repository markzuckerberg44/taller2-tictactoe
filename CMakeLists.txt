cmake_minimum_required(VERSION 3.28)
project(Taller2_tictactoe)

set(CMAKE_CXX_STANDARD 17)

add_executable(Taller2_tictactoe main.cpp
        Tablero.cpp
        Tablero.cpp
        IA_Minimax.h
        IA_Minimax.cpp)
