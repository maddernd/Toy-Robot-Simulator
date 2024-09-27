#include "utils/Direction.h"
#include <algorithm>
#include <stdexcept>

Direction left(Direction dir) {
    switch (dir) {
        case Direction::NORTH: return Direction::WEST;
        case Direction::WEST: return Direction::SOUTH;
        case Direction::SOUTH: return Direction::EAST;
        case Direction::EAST: return Direction::NORTH;
    }
    throw std::invalid_argument("Invalid direction");
}

Direction right(Direction dir) {
    switch (dir) {
        case Direction::NORTH: return Direction::EAST;
        case Direction::EAST: return Direction::SOUTH;
        case Direction::SOUTH: return Direction::WEST;
        case Direction::WEST: return Direction::NORTH;
    }
    throw std::invalid_argument("Invalid direction");
}

Direction directionFromString(const std::string& str) {
    std::string s = str;
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    if (s == "NORTH") return Direction::NORTH;
    if (s == "EAST") return Direction::EAST;
    if (s == "SOUTH") return Direction::SOUTH;
    if (s == "WEST") return Direction::WEST;
    throw std::invalid_argument("Invalid direction string: " + str);
}

std::string directionToString(Direction dir) {
    switch (dir) {
        case Direction::NORTH: return "NORTH";
        case Direction::EAST: return "EAST";
        case Direction::SOUTH: return "SOUTH";
        case Direction::WEST: return "WEST";
    }
    throw std::invalid_argument("Invalid direction");
}