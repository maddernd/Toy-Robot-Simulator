#ifndef RIGHTCOMMAND_H
#define RIGHTCOMMAND_H

#include "Command.h"

class RightCommand : public Command {
public:
    void execute(Robot& robot) override;
};

#endif