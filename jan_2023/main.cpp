#include <iostream>
#include <vector>
using namespace std;

#include "Square.h"

//0 1 4 9
//0 2 5 11
//0 2 6 13
//0 6 17 37
//0 7 20 44
//0 17 48 105

//0 6 9 11
//1 7 10 12
//0 7 11 13
//1 8 12 14
//2 9 13 15
//3 10 14 16
//4 11 15 17

//7 14 18 20

//0 118 335 734

int testSquare(int a, int b, int c, int d){
    Square square(a,b,c,d);
    int count = 1;
    while(true){
        square.newSquare();
        count++;
        if (square.isZero()) break;
    }
    return count;
}

void printSquare(int a, int b, int c, int d){
    Square square(a,b,c,d);
    while(true){
        vector<int> tempArr = square.getSquare();
        for(int i = 0; i < 4; i++){
        cout << tempArr[i] << " ";
        }
        cout << endl;
        square.newSquare();
        if(square.isZero()) break;
    }
    return;
}

int main(){
    int max = 0;
    vector<int> maxArr;
    //int* maxArr = new int[4];

    //Square square(10,6,3,1);

    //cout << testSquare(31, 29, 25, 18);
    // printSquare(44, 37, 24, 0);
    // return 0;

    //numbers range from 0 to 10,000,000 (inclusive)

    int h = 10000;

    //for(int h = 0; h < 50; h++){

    cout << "Max Num Checked: " << h << endl;

    //for(int a = 0; a <= h; a++){
    int a = 0;
    for(int b = 0; b <= h/2; b++){
    for(int c = h/4; c <= 3*h/4; c++){
    for(int d = h/2; d <= h; d++){
        
        Square square(a,b,c,d);

        int count = 1;
        vector<int> tempArr = square.getSquare();

        while(true){
            square.newSquare();
            count++;
            if (square.isZero()) break;
        }

        if(count > max){
            max = count;
            maxArr = tempArr;
        }
        //cout << "Curr Max" << max << endl;

    }}}

    cout << "M: " << max << endl;
    // cout << "Original Values: ";
    for(int i = 0; i < 4; i++){
        cout << maxArr[i] << " ";
    }
    cout << endl;

    //}
}