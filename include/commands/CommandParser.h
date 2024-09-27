#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "Command.h"
#include <string>
#include <memory>

class CommandParser {
public:
    std::unique_ptr<Command> parseCommand(const std::string& input);
};

#endif