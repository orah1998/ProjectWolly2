cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES src/main.cpp src/Board.cpp include/Board.h src/Cell.cpp include/Cell.h src/CellCollection.cpp include/CellCollection.h src/Player.cpp include/Player.h src/GameLogics.cpp include/GameLogics.h src/Winner.cpp include/Winner.h src/GameFlow.cpp include/GameFlow.h src/AI.cpp include/AI.h Tests/CellCollectionTest.cpp Tests/gtest_main.cpp Tests/AITest.cpp Tests/BoardTest.cpp Tests/CellTest.cpp Tests/playerTest.cpp Tests/GameLogicsTest.cpp)
add_executable(untitled ${SOURCE_FILES} Tests/CellCollectionTest.cpp Tests/gtest_main.cpp)
target_link_libraries(untitled gtest gtest_main)