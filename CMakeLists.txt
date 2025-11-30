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
target_link_libraries(runCharTests gmock gtest gtest_main)
SET_TARGET_PROPERTIES(runCharTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)

ADD_EXECUTABLE(runMonsterTests
    test/testMonster.cpp
    src/MonsterStats.cpp
    src/BattleRoom.cpp
    src/BattleMenu.cpp
)
target_link_libraries(runMonsterTests gmock gtest gtest_main)
SET_TARGET_PROPERTIES(runMonsterTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)

ADD_EXECUTABLE(runMapTests
    test/testMap.cpp
    src/Room.cpp
    src/DungeonMap.cpp
    src/MapGenerator.cpp
    src/MapNavigationMenu
    src/EncounterMenu.cpp
)
target_link_libraries(runMapTests gmock gtest gtest_main)
SET_TARGET_PROPERTIES(runMapTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)

ADD_EXECUTABLE(runShopTests
    test/testShop.cpp
    src/shop.cpp
    src/shopRoom.cpp
    src/player.cpp
    src/inventory.cpp
    src/ItemClass.cpp
    src/Items.cpp
    src/boundaryShopMenu.cpp
)
target_link_libraries(runShopTests gmock gtest gtest_main)
SET_TARGET_PROPERTIES(runShopTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)

