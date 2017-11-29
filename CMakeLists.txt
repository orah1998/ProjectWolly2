cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES mainTemp.cpp Board.cpp Board.h Cell.cpp Cell.h CellCollection.cpp CellCollection.h Player.cpp Player.h GameLogics.cpp GameLogics.h Winner.cpp Winner.h GameFlow.cpp GameFlow.h AI.cpp AI.h Tests/CellCollectionTest.cpp Tests/gtest_main.cpp Tests/AITest.cpp Tests/BoardTest.cpp)
add_executable(untitled ${SOURCE_FILES} Tests/CellCollectionTest.cpp Tests/gtest_main.cpp)
target_link_libraries(untitled gtest gtest_main)