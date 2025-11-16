cmake_minimum_required(VERSION 3.10)
project(BattleGame)

include_directories(${CMAKE_SOURCE_DIR}/test/googletest/googletest/include)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/header)

add_subdirectory(test/googletest)

ADD_EXECUTABLE(runAllTests
    test/test.cpp
    src/MonsterStats.cpp
    src/BattleRoom.cpp
    src/BattleMenu.cpp
)
target_link_libraries(runAllTests gmock gtest gtest_main)

