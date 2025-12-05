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
    src/CharacterClass.cpp
)
target_link_libraries(runCharTests gmock gtest gtest_main)
SET_TARGET_PROPERTIES(runCharTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)

ADD_EXECUTABLE(runBattleTests
    test/testBattle.cpp
    src/MonsterStats.cpp
    src/BattleRoom.cpp
    src/BattleMenu.cpp
    src/CharacterClass.cpp
    src/CharacterSelectMenu.cpp
    src/Items.cpp 
    src/ItemClass.cpp  
    src/Skill.cpp
    src/LevelUp.cpp
    src/Combat.cpp
    src/Room.cpp
    src/EncounterMenu.cpp
    )
target_link_libraries(runBattleTests gmock gtest gtest_main)
SET_TARGET_PROPERTIES(runBattleTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
) 

ADD_EXECUTABLE(runMapTests
    test/testMap.cpp
    src/Room.cpp
    src/DungeonMap.cpp
    src/MapGenerator.cpp
    src/MapNavigationMenu
    src/EncounterMenu.cpp
    src/MapDisplayer.cpp
)
target_link_libraries(runMapTests gmock gtest gtest_main)
SET_TARGET_PROPERTIES(runMapTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)

ADD_EXECUTABLE(runShopTests

    test/testShop.cpp
    src/Items.cpp
    src/ItemClass.cpp
    src/Shop.cpp
    src/ShopRoom.cpp
    src/ShopMenu.cpp
    src/CharacterClass.cpp
)

target_link_libraries(runShopTests gmock gtest gtest_main)
SET_TARGET_PROPERTIES(runShopTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)

ADD_EXECUTABLE(runMainDriver
    test/mainDriver.cpp 
    src/StartMenu.cpp
    src/CharacterSelectMenu.cpp
    src/CharacterClass.cpp
    #src/MageClass.cpp
    #src/WarriorClass.cpp
    #src/AssassinClass.cpp
    src/MapNavigationMenu.cpp
    src/MapDisplayer.cpp
    src/DungeonMap.cpp
    src/Room.cpp
    src/MapGenerator.cpp
    src/EncounterMenu.cpp
    
)
SET_TARGET_PROPERTIES(runMainDriver PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)

ADD_EXECUTABLE(runEventSystemTests
    test/testEventSystem.cpp
    src/EncounterMenu.cpp
    src/EventMenu.cpp
    src/Event1.cpp
    src/Event2.cpp
    src/Event3.cpp
    src/Event4.cpp
    src/EventRoom.cpp
    src/Room.cpp
    src/CharacterClass.cpp
)

SET_TARGET_PROPERTIES(runEventSystemTests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)