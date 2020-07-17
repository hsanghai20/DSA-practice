//Link: https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

//The knight is placed on the first block of an empty board and, 
//moving according to the rules of chess, must visit each square exactly once.

// solution(good ques)

#include <bits/stdc++.h> 
using namespace std; 
int sol[8][8];
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
int solveKTUtil(int x, int y, int movei) 
{ 
    int k, next_x, next_y; 
    if (movei==63) 
    {
        for (int x = 0; x < 8; x++) 
        { 
            for (int y = 0; y < 8; y++) 
                cout << " " << setw(2)  
                            << sol[x][y] << " "; 
            cout << endl; 
        }
        return 1; 
    }
    for (k = 0; k < 8; k++) 
    { 
        next_x = x + xMove[k]; 
        next_y = y + yMove[k]; 
        if (next_x >= 0 && next_x < 8 && next_y >= 0 && 
            next_y < 8 && sol[next_x][next_y] == -1) 
        { 
            sol[next_x][next_y] = movei+1; 
            if (solveKTUtil(next_x, next_y,  
                            movei + 1) == 1) 
                return 1; 
            else
                sol[next_x][next_y] = -1; 
        } 
    } 
    return 0; 
} 
int main() 
{ 
    for (int x = 0; x < 8; x++) 
        for (int y = 0; y < 8; y++) 
            sol[x][y] = -1;
    sol[0][0]=0;
    solveKTUtil(0,0,0);
    return 0; 
} 