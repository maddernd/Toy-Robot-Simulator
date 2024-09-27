#include "commands/LeftCommand.h"

void LeftCommand::execute(Robot& robot) {
    robot.turnLeft();
}