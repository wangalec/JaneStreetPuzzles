#ifndef DICE_H
#define DICE_H

class Dice{
private:
    int face_;
    int back_;
    int up_;
    int down_;
    int left_;
    int right_;

public:
    Dice();
    Dice(int face, int back, int up, int down, int left, int right);
    int rollUp();
    int rollDown();
    int rollLeft();
    int rollRight();
};

#endif