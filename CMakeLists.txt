cmake_minimum_required(VERSION 3.10)
project(ToyRobotSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

set(SOURCES
    src/main.cpp
    src/core/Robot.cpp
    src/core/Table.cpp
    src/commands/CommandParser.cpp
    src/commands/LeftCommand.cpp
    src/commands/MoveCommand.cpp
    src/commands/PlaceCommand.cpp
    src/commands/ReportCommand.cpp
    src/commands/RightCommand.cpp
    src/utils/Direction.cpp
)

add_executable(toy_robot ${SOURCES})

enable_testing()

add_subdirectory(googletest) 
include_directories(googletest/googletest/include)

set(TEST_SOURCES
    test/test_robot.cpp
    src/core/Robot.cpp
    src/core/Table.cpp
    src/commands/CommandParser.cpp
    src/commands/LeftCommand.cpp 
    src/commands/MoveCommand.cpp  
    src/commands/PlaceCommand.cpp  
    src/commands/ReportCommand.cpp  
    src/commands/RightCommand.cpp  
    src/utils/Direction.cpp
)

add_executable(test_robot ${TEST_SOURCES})

target_link_libraries(test_robot gtest gtest_main)

add_test(NAME RobotTests COMMAND test_robot)
