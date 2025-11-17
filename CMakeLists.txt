PROJECT(CharacterProject)

SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(
    header
    googletest/googletest/include
    googletest/googlemock/include
)

add_subdirectory(googletest)

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
    test/test.cpp
    src/DungeonMap.cpp
    src/MapGenerator.cpp
    src/MapNavigationMenu.cpp
    src/Room.cpp
)
target_link_libraries(runMapTests gmock gtest gtest_main)

SET_TARGET_PROPERTIES(runAllTests PROPERTIES
RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)