#ifndef ROBOT_H
#define ROBOT_H

#include "core/Table.h"
#include "utils/Direction.h"

class Robot {
public:
    Robot(const Table& table);

    bool isPlaced() const;

    void place(int x, int y, Direction facing);

    void move();

    void turnLeft();

    void turnRight();

    void report() const;
    // Getter methods for testing
    int getX() const;
    int getY() const;
    Direction getFacing() const;

private:
    int x_;
    int y_;
    Direction facing_;
    bool placed_;
    const Table& table_;
};

#endif