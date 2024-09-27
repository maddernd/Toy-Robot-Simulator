#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"

class MoveCommand : public Command {
public:
    void execute(Robot& robot) override;
};

#endif