#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Interactable.hpp"
#include "Helper.hpp"
#include "Robot.hpp"

class Obstacle: public Interactable {
public:
    Obstacle(int x, int y, int width, int height): Interactable(x, y, width, height) {
        _type = OBSTACLE;
    }
    Obstacle(): Obstacle(0, 0, 0, 0) {}

    bool interact(Robot* player) {
        if (!Helper::euclideanDistance(player->getCoordinates(), this->getCoordinates())) {
            player->takeHit();
            if (!player->getHealth()) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    InteractableType getType() {
        return _type;
    }
};

#endif