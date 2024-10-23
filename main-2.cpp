#include "Helper.hpp"
#include "Goal.hpp"
#include "Obstacle.hpp"
#include "Robot.hpp"
#include <iostream>
using namespace std;

int main() {
    Robot player(3, 1);
    Goal goal(3,1);
    Obstacle obstacle(2, 0, 3, 1);
    cout << "player pos: " << player.getCoordinates().first << " , " << player.getCoordinates().second << endl;
    return 0;
}