#include "commands/ReportCommand.h"

void ReportCommand::execute(Robot& robot) {
    robot.report();
}