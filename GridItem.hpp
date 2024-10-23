
#ifndef GRIDITEM_H
#define GRIDITEM_H

#include <utility>
using namespace std;

class GridItem {
protected:
    pair<int, int> _position;
    int _width;
    int _height;
    static int _activeGridItemCount;

public:
    GridItem(int x, int y, int width, int height): _position({x, y}), _width(width), _height(height) {
        _activeGridItemCount++;
    }

    GridItem(): GridItem(0, 0, 0, 0) {}
    virtual ~GridItem() {
        _activeGridItemCount--;
    }
    void setCoordinates(int x, int y) {
        _position = {x, y};
    }
    pair<int, int> getCoordinates() {
        return _position;
    }
    int getGridWidth() {
        return _width;
    }
    int getGridHeight() {
        return _height;
    }
    int getActiveGridItemCount() {
        return _activeGridItemCount;
    }
};

int GridItem::_activeGridItemCount = 0;


#endif

