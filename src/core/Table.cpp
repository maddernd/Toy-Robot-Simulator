#include "core/Table.h"

Table::Table(int width, int height)
    : width_(width), height_(height) {}

bool Table::isValidPosition(int x, int y) const {
    return x >= 0 && x < width_ && y >= 0 && y < height_;
}