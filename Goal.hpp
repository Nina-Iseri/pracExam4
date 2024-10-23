#ifndef GOAL_H
#define GOAL_H

#include "Interactable.hpp"
#include "Helper.hpp"
#include "Robot.hpp"

class Goal: public Interactable {
public:
    Goal(int width, int height): Interactable(width - 1, height - 1, width, height) {
        _type = GOAL;
    }
    Goal(): Goal(0, 0) {}

    bool interact(Robot* player) {
        if (!Helper::euclideanDistance(player->getCoordinates(), this->getCoordinates())) {
            return true;
        } else {
            return false;
        }
    }

    InteractableType getType() {
        return _type;
    }
};

#endif