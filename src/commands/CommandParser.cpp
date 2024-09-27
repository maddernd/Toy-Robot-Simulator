#include "commands/CommandParser.h"
#include "commands/PlaceCommand.h"
#include "commands/MoveCommand.h"
#include "commands/LeftCommand.h"
#include "commands/RightCommand.h"
#include "commands/ReportCommand.h"
#include "utils/Direction.h"
#include <sstream>
#include <algorithm>
#include <cctype>

std::unique_ptr<Command> CommandParser::parseCommand(const std::string& input) {
    std::string commandStr = input;
    commandStr.erase(0, commandStr.find_first_not_of(" \t\n\r\f\v"));
    commandStr.erase(commandStr.find_last_not_of(" \t\n\r\f\v") + 1);
    std::transform(commandStr.begin(), commandStr.end(), commandStr.begin(), ::toupper);

    if (commandStr.find("PLACE") == 0) {
        size_t spacePos = commandStr.find(' ');
        if (spacePos == std::string::npos) {
            return nullptr;
        }
        std::string args = commandStr.substr(spacePos + 1);
        args.erase(std::remove_if(args.begin(), args.end(), ::isspace), args.end());
        std::replace(args.begin(), args.end(), ',', ' ');
        std::stringstream ss(args);
        int x, y;
        std::string dirStr;
        ss >> x >> y >> dirStr;
        if (ss.fail() || !ss.eof()) {
            return nullptr;
        }
        try {
            Direction dir = directionFromString(dirStr);
            return std::make_unique<PlaceCommand>(x, y, dir);
        } catch (const std::invalid_argument&) {
            return nullptr;
        }
    } else if (commandStr == "MOVE") {
        return std::make_unique<MoveCommand>();
    } else if (commandStr == "LEFT") {
        return std::make_unique<LeftCommand>();
    } else if (commandStr == "RIGHT") {
        return std::make_unique<RightCommand>();
    } else if (commandStr == "REPORT") {
        return std::make_unique<ReportCommand>();
    }
    return nullptr;
}