#include "core/Robot.h"
#include "core/Table.h"
#include "commands/CommandParser.h"
#include <iostream>
#include "commands/PlaceCommand.h"

int main() {
    Table table(5, 5);
    Robot robot(table);
    CommandParser parser; 

    std::string line;
    while (std::getline(std::cin, line)) {

        auto command = parser.parseCommand(line);

        if (!command) {
            std::cout << "Invalid command. Please try again." << std::endl;
            continue;  
        }

        if (!robot.isPlaced() && dynamic_cast<PlaceCommand*>(command.get()) == nullptr) {
            std::cout << "The robot must be placed using the PLACE command before other commands." << std::endl;
        } else {
            command->execute(robot);
        }
    }      
    return 0;
}
