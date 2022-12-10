#include "Dice.h"

Dice::Dice(){

}

Dice::Dice(int face, int back, int up, int down, int left, int right){
    face_ = face;
    back_ = back;
    up_ = up;
    down_ = down;
    left_ = left;
    right_ = right;
}

int Dice::rollUp(){
    int temp = face_;
    face_ = down_;
    down_ = back_;
    back_ = up_;
    up_ = temp;
    return face_;
}

int Dice::rollDown(){
    int temp = face_;
    face_ = up_;
    up_ = back_;
    back_ = down_;
    down_ = temp;
    return face_;
}

int Dice::rollLeft(){
    int temp = face_;
    face_ = right_;
    right_ = back_;
    back_ = left_;
    left_ = temp;
    return face_;
}

int Dice::rollRight(){
    int temp = face_;
    face_ = left_;
    left_ = back_;
    back_ = right_;
    right_ = temp;
    return face_;
}

int Dice::checkUp(){
    return down_;
}

int Dice::checkDown(){
    return up_;
}

int Dice::checkLeft(){
    return right_;
}

int Dice::checkRight(){
    return left_;
}


