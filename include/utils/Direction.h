#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

Direction left(Direction dir);
Direction right(Direction dir);
Direction directionFromString(const std::string& str);
std::string directionToString(Direction dir);

#endif