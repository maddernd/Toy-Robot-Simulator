#ifndef REPORTCOMMAND_H
#define REPORTCOMMAND_H

#include "Command.h"

class ReportCommand : public Command {
public:
    void execute(Robot& robot) override;
};

#endif 