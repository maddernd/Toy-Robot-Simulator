#ifndef TABLE_H
#define TABLE_H

class Table {
public:
    Table(int width, int height);

    bool isValidPosition(int x, int y) const;

private:
    int width_;
    int height_;
};

#endif