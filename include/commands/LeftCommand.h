#ifndef LEFTCOMMAND_H
#define LEFTCOMMAND_H

#include "Command.h"

class LeftCommand : public Command {
public:
    void execute(Robot& robot) override;
};

#endif 