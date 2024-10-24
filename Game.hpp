#ifndef GAME_H
#define GAME_H

#include "Helper.hpp"
#include "Goal.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"
#include <iostream>
#include <vector>
using namespace std;

enum GameState{
    WIN,
    LOSE,
    PLAYING
};

class Game {
    int _width;
    int _height;
    Robot _player;
    Goal _goal;
    vector<Obstacle*> _obstacles;
    GameState _state;
    
public:
    Game(int width, int height, vector<pair<int, int>> obstacleCoordinates): _player(width, height), _goal(width, height) {
        _width = width;
        _height = height;
        for (size_t i = 0; i < obstacleCoordinates.size(); ++i) {
            if (obstacleCoordinates[i] != _player.getCoordinates() && obstacleCoordinates[i] != _goal.getCoordinates()) {
                int x = obstacleCoordinates[i].first;
                int y = obstacleCoordinates[i].second;
                Obstacle* new_obstacle = new Obstacle(x, y, width, height);
                _obstacles.push_back(new_obstacle);
            }
        }
    }
    ~Game() {
        for (size_t i = 0; i < _obstacles.size(); ++i) {
            delete _obstacles[i];
        }
    }

    bool displayState() {
        if (_state == WIN) {
            cout << "You win!" << endl;
            return true;
        } else if (_state == LOSE) {
            cout << "You lose :(" << endl;
            return true;
        } else if (_state == PLAYING) {
            cout << "Game on" << endl;
            return false;
        }
        return false;
    }

    void movePlayer(int dx, int dy) {
        if (dx > 0) {
            for (int i = 0; i < dx; ++i) {
                if (!_player.move(1, 0)) break;
                if (_goal.interact(&_player)) {
                    _state = WIN;
                    break;
                }
                for (size_t i = 0; i < _obstacles.size(); ++i) {
                    if (!_obstacles[i]->interact(&_player)) break;
                }
                if (!_player.getHealth()) {
                    _state = LOSE;
                    break;
                }
            }
        } else if (dx < 0) {
            for (int i = 0; i < -dx; ++i) {
                if (!_player.move(-1, 0)) break;
                if (_goal.interact(&_player)) {
                    _state = WIN;
                    break;
                }
                for (size_t i = 0; i < _obstacles.size(); ++i) {
                    if (!_obstacles[i]->interact(&_player)) break;
                }
                if (!_player.getHealth()) {
                    _state = LOSE;
                    break;
                }
            }
        }

        if (_state != PLAYING) return;

        if (dy > 0) {
            for (int i = 0; i < dy; ++i) {
                if (!_player.move(0, 1)) break;
                if (_goal.interact(&_player)) {
                    _state = WIN;
                    break;
                }
                for (size_t i = 0; i < _obstacles.size(); ++i) {
                    if (!_obstacles[i]->interact(&_player)) break;
                }
                if (!_player.getHealth()) {
                    _state = LOSE;
                    break;
                }
            }
        } else if (dy < 0) {
            for (int i = 0; i < -dy; ++i) {
                if (!_player.move(0, -1)) break;
                if (_goal.interact(&_player)) {
                    _state = WIN;
                    break;
                }
                for (size_t i = 0; i < _obstacles.size(); ++i) {
                    if (!_obstacles[i]->interact(&_player)) break;
                }
                if (!_player.getHealth()) {
                    _state = LOSE;
                    break;
                }
            }
        }

        if (_state != PLAYING) return;
    }

    void printGrid() {
        for (int i = 0; i < _height; ++i) {
            for (int j = 0; j < _width; ++j) {
                bool is_taken = false;
                if (_player.getCoordinates() == pair<int, int>({j, i})) {
                    cout << "P";
                    continue;
                } else if (_goal.getCoordinates() == pair<int, int>({j, i})) {
                    cout << "G";
                    continue;
                }
                for (size_t k = 0; k < _obstacles.size(); ++k) {
                    if (_obstacles[k]->getCoordinates() == pair<int, int>({j, i})) {
                        cout << "O";
                        is_taken = true;
                        break;
                    }
                }
                if (!is_taken) {
                    cout << "_";
                }
            }
            cout << endl;
        }
    }
};

#endif