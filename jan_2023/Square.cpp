#include <cmath>
#include <vector>
using namespace std;
#include "Square.h"

Square::Square(int corner1, int corner2, int corner3, int corner4){
    corner1_ = corner1;
    corner2_ = corner2;
    corner3_ = corner3;
    corner4_ = corner4;
}

vector<int> Square::getSquare(){
    vector<int> arr;
    arr.push_back(corner1_);
    arr.push_back(corner2_);
    arr.push_back(corner3_);
    arr.push_back(corner4_);
    return arr;
}

void Square::newSquare(){
    int corner1 = corner1_;
    int corner2 = corner2_;
    int corner3 = corner3_;
    int corner4 = corner4_;

    corner1_ = abs(corner1-corner2);
    corner2_ = abs(corner2-corner3);
    corner3_ = abs(corner3-corner4);
    corner4_ = abs(corner4-corner1);
}

bool Square::isZero(){
    return (corner1_ + corner2_ + corner3_ + corner4_) == 0;
}

