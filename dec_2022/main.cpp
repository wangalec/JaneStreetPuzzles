#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>

using namespace std;

#include "Dice.h"

vector<int> search(){
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

    // int range = 10;

    // for(int a = -range; a <= range; a++){
    // face = a;
        
    // for(int b = -range; b <= range; b++){
    // back = b;
        
    // for(int c = -range; c <= range; c++){
    // up = c;
            
    // for(int d = -range; d <= range; d++){
    // left = d;
                
    // for(int e = -range; e <= range; e++){
    // right = e;
    // down = 5;

    rand()&(20+1) - 10;


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
                cout << endl << "Dice: " << endl 
                << "Face: " << face << " | Back: " << back
                << " | Up: " << up << " | Down: " << down
                << " | Left: " << left << " | Right: " << right << endl;
                return path;
            }

            //up
            if(y + 1 < 6){
                //cout << "up avail" << endl;
                int result = n*dice.checkUp();
                //cout << result/n << endl;
                if(score + result == grid[y+1][x]){
                    score += result;
                    dice.rollUp();
                    path.push_back(score);
                    y += 1;
                    //cout << "up" << endl;
                    continue;
                }
            }
            //down
            if(y - 1 >= 0){
                //cout << "down avail" << endl;
                int result = n*dice.checkDown();
                //cout << result/n << endl;
                if(score + result == grid[y-1][x]){
                    score += result;
                    dice.rollDown();
                    path.push_back(score);
                    y -= 1;
                    //cout << "down" << endl;
                    continue;
                }
            }
            //left
            if(x - 1 >= 0){
                //cout << "left avail" << endl;
                int result = n*dice.checkLeft();
                //cout << result/n << endl;
                if(score + result == grid[y][x-1]){
                    score += result;
                    dice.rollLeft();
                    path.push_back(score);
                    x -= 1;
                    //cout << "left" << endl;
                    continue;
                }
            }
            //right
            if(x + 1 < 6){
                //cout << "right avail" << endl;
                int result = n*dice.checkRight();
                //cout << result/n << endl;
                if(score + result == grid[y][x+1]){
                    score += result;
                    dice.rollRight();
                    path.push_back(score);
                    x += 1;
                    //cout << "right" << endl;
                    continue;
                }
            }
            //if none of the paths are viable, break out of the loop
            cout << "Failed at " << grid[y][x] << endl;
            break;
        }
    // }}}}}
}


int main(){

    // Path: 
    // 5 23 -4 32 77 23 2 42 123 33 132 240 123 81 186 42 195 357 452 592 403 337 452 620 395 317 452 704 443 353 508 732 
    // Dice: 
    // Face: 9 | Back: 7 | Up: -9 | Down: 5 | Left: 9 | Right: -3
    // ANSWER: 301360

    //Execution Time of 162 seconds by tipping to check and tipping back if it doesn't work
    //Execution Time of 94 seconds by only checking if the dice can go to the point
    //74 seconds -10

    int grid[6][6] = {
        {0, 77, 32, 403, 337, 452},
        {5, 23, -4, 592, 445, 620},
        {-7, 2, 357, 452, 317, 395},
        {186, 42, 195, 704, 452, 228},
        {81, 123, 240, 443, 353, 508},
        {57, 33, 132, 268, 492, 732}
    };

    auto start = chrono::high_resolution_clock::now();

    vector<int> result = search();

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
    cout << "Execution Time (seconds): " << duration.count() << endl;

    //loop through matrix to see if numbers have gone through

    unordered_set<int> result_map;

    for(int i = 0; i < result.size(); i++){
        if (result_map.find(result.at(i)) == result_map.end()){
            result_map.insert(result.at(i));
        }
    }

    int ans = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if (result_map.find(grid[i][j]) == result_map.end()){
                ans += grid[i][j];
                cout << grid[i][j] << " added" << endl;
            }
        }
    }
    cout << "ANSWER: " << ans << endl;
}