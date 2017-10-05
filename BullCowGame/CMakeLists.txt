cmake_minimum_required(VERSION 3.8)
project(BullCowGame)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        FBullCowGame.cpp
        FBullCowGame.h
        main.cpp)

add_executable(BullCowGame ${SOURCE_FILES})