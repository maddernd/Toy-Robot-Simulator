#ifndef PLACECOMMAND_H
#define PLACECOMMAND_H

#include "Command.h"
#include "utils/Direction.h"

class PlaceCommand : public Command {
public:
    PlaceCommand(int x, int y, Direction facing);

    void execute(Robot& robot) override;

private:
    int x_;
    int y_;
    Direction facing_;
};

#endif