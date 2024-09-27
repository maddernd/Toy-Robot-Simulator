#include "commands/MoveCommand.h"

void MoveCommand::execute(Robot& robot) {
    robot.move();
}