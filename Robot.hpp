#ifndef ROBOT_H
#define ROBOT_H

#include "GridItem.hpp"

class Robot: public GridItem {
private:
    int _health;
public:
    Robot(int gridWidth, int gridHeight): GridItem(0, 0, gridWidth, gridHeight) {
        _health = 3;
    }

    int getHealth() {
        return _health;
    }

    void takeHit() {
        if (_health > 0) _health--;
    }

    bool move(int xOffset, int yOffset) {
        if (xOffset != 0 && yOffset != 0) return false;
        int x = getCoordinates().first + xOffset;
        int y = getCoordinates().second + yOffset;
        if (x< 0 || x >= getGridWidth()) return false;
        if (y < 0 || y >= getGridHeight()) return false;
        setCoordinates(x, y);
        return true;
    }

};

#endif