#include <gtest/gtest.h>
#include "core/Robot.h"
#include "core/Table.h"
#include "utils/Direction.h"
#include "commands/CommandParser.h"
#include <sstream>
#include <iostream>
#include <string>

std::string captureReportOutput(Robot& robot) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    robot.report();
    std::cout.rdbuf(old);
    return buffer.str();
}

class RobotTest : public ::testing::Test {
protected:
    Table table{5, 5};
    Robot robot{table};
};

TEST_F(RobotTest, InitialState) {
    EXPECT_FALSE(robot.isPlaced());
}

TEST_F(RobotTest, ValidPlaceCommand) {
    robot.place(0, 0, Direction::NORTH);
    EXPECT_TRUE(robot.isPlaced());
    EXPECT_EQ(robot.getX(), 0);
    EXPECT_EQ(robot.getY(), 0);
    EXPECT_EQ(robot.getFacing(), Direction::NORTH);
}

TEST_F(RobotTest, MoveCommandNorth) {
    robot.place(0, 0, Direction::NORTH);
    robot.move();
    EXPECT_EQ(robot.getY(), 1);
}

TEST_F(RobotTest, TurnLeftCommand) {
    robot.place(0, 0, Direction::NORTH);
    robot.turnLeft();
    EXPECT_EQ(robot.getFacing(), Direction::WEST);
}

TEST_F(RobotTest, TurnRightCommand) {
    robot.place(0, 0, Direction::NORTH);
    robot.turnRight();
    EXPECT_EQ(robot.getFacing(), Direction::EAST);
}

TEST_F(RobotTest, ReportCommandOutput) {
    robot.place(0, 1, Direction::NORTH);
    std::string output = captureReportOutput(robot);
    EXPECT_EQ(output, "0,1,NORTH\n");
}

TEST_F(RobotTest, CommandsIgnoredBeforePlace) {
    robot.move();
    robot.turnLeft();
    robot.report();
    EXPECT_FALSE(robot.isPlaced());
}

TEST_F(RobotTest, InvalidPlaceCommandInvalidDirection) {
    EXPECT_THROW(
        robot.place(0, 0, static_cast<Direction>(-1)),
        std::invalid_argument
    );
}

TEST_F(RobotTest, PreventFallingOffTableNorth) {
    robot.place(0, 4, Direction::NORTH);
    robot.move();
    EXPECT_EQ(robot.getY(), 4);
}

TEST_F(RobotTest, PreventFallingOffTableEast) {
    robot.place(4, 0, Direction::EAST);
    robot.move();
    EXPECT_EQ(robot.getX(), 4);
}

TEST_F(RobotTest, PreventFallingOffTableSouth) {
    robot.place(0, 0, Direction::SOUTH);
    robot.move();
    EXPECT_EQ(robot.getY(), 0);
}

TEST_F(RobotTest, PreventFallingOffTableWest) {
    robot.place(0, 0, Direction::WEST);
    robot.move();
    EXPECT_EQ(robot.getX(), 0);
}

TEST_F(RobotTest, MultiplePlaceCommands) {
    robot.place(0, 0, Direction::NORTH);
    robot.move();
    EXPECT_EQ(robot.getY(), 1);

    robot.place(3, 3, Direction::EAST);
    EXPECT_EQ(robot.getX(), 3);
    EXPECT_EQ(robot.getY(), 3);
    EXPECT_EQ(robot.getFacing(), Direction::EAST);
}

TEST_F(RobotTest, ComplexSequenceOfCommands) {
    robot.place(1, 2, Direction::EAST);
    robot.move();
    robot.move();
    robot.turnLeft();
    robot.move();
    EXPECT_EQ(robot.getX(), 3);
    EXPECT_EQ(robot.getY(), 3);
    EXPECT_EQ(robot.getFacing(), Direction::NORTH);
}

TEST_F(RobotTest, FullRotation) {
    robot.place(2, 2, Direction::NORTH);
    robot.turnRight();
    robot.turnRight();
    robot.turnRight();
    robot.turnRight();
    EXPECT_EQ(robot.getFacing(), Direction::NORTH);
}

TEST_F(RobotTest, InvalidPlaceCommandsIgnore) {
    robot.place(2, 2, Direction::NORTH);
    int x_before = robot.getX();
    int y_before = robot.getY();
    Direction facing_before = robot.getFacing();

    robot.place(-1, -1, Direction::SOUTH);
    EXPECT_EQ(robot.getX(), x_before);
    EXPECT_EQ(robot.getY(), y_before);
    EXPECT_EQ(robot.getFacing(), facing_before);
}

TEST_F(RobotTest, ReplacedAfterBeingPlaced) {
    robot.place(1, 1, Direction::NORTH);
    EXPECT_TRUE(robot.isPlaced());
    robot.move();
    robot.place(2, 2, Direction::EAST);
    EXPECT_EQ(robot.getX(), 2);
    EXPECT_EQ(robot.getY(), 2);
    EXPECT_EQ(robot.getFacing(), Direction::EAST);
}

TEST_F(RobotTest, ReportAfterMultipleCommands) {
    robot.place(2, 2, Direction::EAST);
    std::string output = captureReportOutput(robot);
    EXPECT_EQ(output, "2,2,EAST\n");
}

TEST_F(RobotTest, InvalidPlaceCommandOutOfBounds) {
    std::stringstream buffer;
    std::streambuf* old = std::cerr.rdbuf(buffer.rdbuf());  

    robot.place(-2, 0, Direction::NORTH);
    EXPECT_EQ(buffer.str(), "Error: Please PLACE the robot within the the map.\n");

    std::cerr.rdbuf(old); 

    EXPECT_FALSE(robot.isPlaced());
}
TEST_F(RobotTest, InvalidCommand) {
    CommandParser parser;
    auto command = parser.parseCommand("JUMP");
    EXPECT_EQ(command, nullptr);
}


TEST_F(RobotTest, CommandBeforePlaceIgnored) {
    robot.move();
    robot.turnLeft();
    robot.turnRight();
    EXPECT_FALSE(robot.isPlaced());  
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
