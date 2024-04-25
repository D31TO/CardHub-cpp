cmake_minimum_required(VERSION 3.28)
project(CardHub)

set(CMAKE_CXX_STANDARD 14)

include_directories(CardHub)

add_executable(CardHub
        CardHub/Card.cpp
        CardHub/Card.h
        CardHub/CardHub.cpp
        CardHub/Deck.cpp
        CardHub/Deck.h)
