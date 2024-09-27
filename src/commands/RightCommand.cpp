#include "commands/RightCommand.h"

void RightCommand::execute(Robot& robot) {
    robot.turnRight();
}