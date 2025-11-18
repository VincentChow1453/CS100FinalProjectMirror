cmake_minimum_required(VERSION 3.10)
project(BattleGame)

include_directories(${CMAKE_SOURCE_DIR}/test/googletest/googletest/include)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/header)

add_subdirectory(test/googletest)

SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(
    header
    googletest/googletest/include
    googletest/googlemock/include
)


ADD_EXECUTABLE(runCharTests
    test/testCharacterClass.cpp
    src/characterClass.cpp
)

TARGET_LINK_LIBRARIES(runCharTests
    gtest
    gmock
    gtest_main
)

ADD_EXECUTABLE(runMapTests
    test/testMap.cpp
    src/MonsterStats.cpp
    src/BattleRoom.cpp
    src/BattleMenu.cpp
)
target_link_libraries(runMapTests gmock gtest gtest_main)

SET_TARGET_PROPERTIES(runAllTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)