cmake_minimum_required(VERSION 3.12)
project(GoFish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoFish
        go_fish.txt go_fish.cpp player.cpp player.h deck.cpp deck.h card.cpp card.h)
