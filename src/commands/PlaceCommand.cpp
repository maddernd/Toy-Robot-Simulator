#include "commands/PlaceCommand.h"

PlaceCommand::PlaceCommand(int x, int y, Direction facing)
    : x_(x), y_(y), facing_(facing) {}

void PlaceCommand::execute(Robot& robot) {
    robot.place(x_, y_, facing_);
}