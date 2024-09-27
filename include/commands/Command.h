#ifndef COMMAND_H
#define COMMAND_H

#include "core/Robot.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Robot& robot) = 0;
};

#endif