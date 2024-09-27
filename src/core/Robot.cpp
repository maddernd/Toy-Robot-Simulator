#include "core/Robot.h"
#include <iostream>

Robot::Robot(const Table& table)
    : x_(0), y_(0), facing_(Direction::NORTH), placed_(false), table_(table) {}

bool Robot::isPlaced() const {
    return placed_;
}

void Robot::place(int x, int y, Direction facing) {
    if (!table_.isValidPosition(x, y)) {
        std::cerr << "Error: Please PLACE the robot within the the map." << std::endl;
        return;
    }
    if (facing < Direction::NORTH || facing > Direction::WEST) {
        throw std::invalid_argument("Invalid direction");
    }
    x_ = x;
    y_ = y;
    facing_ = facing;
    placed_ = true;
}

void Robot::move() {
    if (!placed_) return;
    int newX = x_;
    int newY = y_;
    switch (facing_) {
        case Direction::NORTH: newY++; break;
        case Direction::EAST: newX++; break;
        case Direction::SOUTH: newY--; break;
        case Direction::WEST: newX--; break;
    }
    if (table_.isValidPosition(newX, newY)) {
        x_ = newX;
        y_ = newY;
    } else {
        std::cerr << "Error: The robot cannot move outside the boundaries of the table.\n";
    }
}

void Robot::turnLeft() {
    if (!placed_) return;
    facing_ = left(facing_);
}

void Robot::turnRight() {
    if (!placed_) return;
    facing_ = right(facing_);
}

void Robot::report() const {
    if (!placed_) return;
    std::cout << x_ << "," << y_ << "," << directionToString(facing_) << std::endl;
}

int Robot::getX() const {
    return x_;
}

int Robot::getY() const {
    return y_;
}

Direction Robot::getFacing() const {
    return facing_;
}