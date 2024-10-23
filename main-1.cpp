#include "Helper.hpp"
#include "GridItem.hpp"
#include <iostream>
using namespace std;

int main() {
    GridItem init(0, 0, 3, 4), someone(1, 2, 3, 4);
    cout << "init pos: " << init.getCoordinates().first << " , " << init.getCoordinates().second << endl;
    cout << "some pos: " << someone.getCoordinates().first << " , " << someone.getCoordinates().second << endl;
    cout << "distance: " << Helper::euclideanDistance(init.getCoordinates(), someone.getCoordinates()) << endl;
    return 0;
}