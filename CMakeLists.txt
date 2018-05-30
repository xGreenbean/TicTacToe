cmake_minimum_required(VERSION 3.9)
project(cpp_6)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_6 main.cpp Board.cpp Board.h IllegalCharException.cpp IllegalCharException.h IllegalCoordinateException.cpp IllegalCoordinateException.h Piece.cpp Piece.h DummyPlayers.h Player.h DummyPlayers.cpp Champion.h TicTacToe.cpp TicTacToe.h Player.cpp Champion.cpp Draw.cpp Draw.h)