CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

add_subdirectory(test/googletest)

ADD_EXECUTABLE(runAllTests
    test/test.cpp
    src/DungeonMap.cpp
    src/MapGenerator.cpp
    src/MapNavigationMenu.cpp
    src/Room.cpp
)
target_link_libraries(runAllTests gmock gtest gtest_main)


ADD_EXECUTABLE(runTerminalTests
    test/testTerminal.cpp
    src/DungeonMap.cpp
    src/MapGenerator.cpp
    src/MapNavigationMenu.cpp
    src/Room.cpp
)