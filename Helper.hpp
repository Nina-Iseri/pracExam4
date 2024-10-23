
#ifndef HELPER_H
#define HELPER_H

#include <utility>
#include <cmath>
using namespace std;

class Helper { 
public:
    static double euclideanDistance(std::pair<int, int> item1, std::pair<int, int> item2) {
        int dx = item1.first - item2.first;
        int dy = item1.second - item2.second;
        return sqrt(dx * dx + dy * dy);
    }

};

#endif