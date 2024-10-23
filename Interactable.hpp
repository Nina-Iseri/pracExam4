#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include "GridItem.hpp"

class Robot;

enum InteractableType { 
    GOAL,
    OBSTACLE
};

class Interactable: public GridItem {
protected:
    InteractableType _type;
    static int _activeInteractableCount;
public:
    Interactable(int x, int y, int width, int height): GridItem(x, y, width, height) {
        _activeInteractableCount++;
    }
    Interactable(): Interactable(0, 0, 0, 0) {}

    virtual bool interact(Robot* player) = 0;
    virtual InteractableType getType() = 0;

    int getActiveInteractableCount() {
        return _activeInteractableCount;
    }

    virtual ~Interactable() {
        _activeInteractableCount--;
    }\

};

int Interactable::_activeInteractableCount = 0;

#endif