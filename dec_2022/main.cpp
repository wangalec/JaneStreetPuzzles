#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

#include "Dice.h"

int search(){
    int n = 0; //starting value
    int grid[6][6] = {
        {0, 77, 32, 403, 337, 452},
        {5, 23, -4, 592, 445, 620},
        {-7, 2, 357, 452, 317, 395},
        {186, 42, 195, 704, 452, 228},
        {81, 123, 240, 443, 353, 508},
        {57, 33, 132, 268, 492, 732}
    };

    int face = 9, back = 7, up = -9, down = 5, left = 9, right = -3;


    for(int a = -12; a < 12; a++){
    face = a;
        
    for(int b = -12; b < 12; b++){
    back = b;
        
    for(int c = -12; c < 12; c++){
    up = c;
            
    for(int d = -12; d < 12; d++){
    left = d;
                
    for(int e = -12; e < 12; e++){
    right = e;
    down = 5;


        Dice dice(
            face,
            back,
            up, 
            down,
            left,
            right
        );
        //positions
        int x = 0; 
        int y = 0;
        vector<int> path;
        n = 0;
        int score = 0;

        cout << face << back << up << down << left << right << endl;

        while(true){
            cout << "n: " << n << " | square: " << grid[y][x] << endl;
            n++;
            if (score == 732) {
                cout << "PATH FOUND" << endl
                << "Path: " << endl;
                for(int i = 0; i < path.size(); i++){
                    cout << path[i] << " ";
                }
                cout << "Dice: " << endl 
                << "Face: " << face << " | Back: " << back
                << " | Up: " << up << " | Down: " << down
                << " | Left: " << left << " | Right: " << right << endl;
                return 0;
            }

            //up
            if(y + 1 < 6){
                //cout << "up avail" << endl;
                int result = n*dice.rollUp();
                //cout << result/n << endl;
                //cout << result << endl;
                //cout << x << y << endl;
                if(score + result == grid[y+1][x]){
                    score += result;
                    path.push_back(score);
                    y += 1;
                    //cout << "up" << endl;
                    continue;
                }
                dice.rollDown();
            }
            //down
            if(y - 1 >= 0){
                //cout << "down avail" << endl;
                int result = n*dice.rollDown();
                //cout << result/n << endl;
                if(score + result == grid[y-1][x]){
                    score += result;
                    path.push_back(score);
                    y -= 1;
                    //cout << "down" << endl;
                    continue;
                }
                dice.rollUp();
            }
            //left
            if(x - 1 >= 0){
                //cout << "left avail" << endl;
                int result = n*dice.rollLeft();
                //cout << result/n << endl;
                if(score + result == grid[y][x-1]){
                    score += result;
                    path.push_back(score);
                    x -= 1;
                    //cout << "left" << endl;
                    continue;
                }
                dice.rollRight();
            }
            //right
            if(x + 1 < 6){
                //cout << "right avail" << endl;
                int result = n*dice.rollRight();
                //cout << result/n << endl;
                if(score + result == grid[y][x+1]){
                    score += result;
                    path.push_back(score);
                    x += 1;
                    //cout << "right" << endl;
                    continue;
                }
                dice.rollLeft();
            }
            //if none of the paths are viable, break out of the loop
            cout << "Failed at " << grid[y][x] << endl;
            break;
        }
    }}}}}
}


int main(){
    //testing
    // int face = 0, back = 0, up = 0, down = 5, left = 0, right = 0;

    // Dice dice(
    //     face,
    //     back,
    //     up, 
    //     down,
    //     left,
    //     right
    // );

    // cout << dice.rollUp() << endl;
    auto start = chrono::high_resolution_clock::now();
    search();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
    cout << "Execution Time (seconds): " << duration.count() << endl;

}