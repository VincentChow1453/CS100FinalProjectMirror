CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(CharacterProject)

SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(
    header
    googletest/googletest/include
    googletest/googlemock/include
)

add_subdirectory(googletest)

ADD_EXECUTABLE(runAllTests
    test/testCharacterClass.cpp
    src/characterClass.cpp
)

TARGET_LINK_LIBRARIES(runAllTests
    gtest
    gmock
    gtest_main
)

SET_TARGET_PROPERTIES(runAllTests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/test"
)