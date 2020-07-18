//Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// A rat starts from source and has to reach the destination. The rat can move only in two directions: forward and down.
//In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination.

// solution
#include <bits/stdc++.h> 
using namespace std;
#define N 4
int maze[N][N] = { { 1, 0, 0, 0 }, 
                    { 1, 1, 0, 1 }, 
                   { 0, 1, 0, 0 }, 
                   { 1, 1, 1, 1 } 
                }; 
int ans[N][N];
bool isvalid(int i,int j)
{
    return (i>=0 && i<N && j>=0 && j<N && maze[i][j]==1);
}
bool solvemaze(int i,int j)
{
    if(i==N-1 && j==N-1 && maze[N-1][N-1]==1)
    {
        ans[i][j]=1;
        for(int k=0;k<N;k++)
        {
            for(int l=0;l<N;l++)
                cout << ans[k][l] << " ";
            cout << endl;
        }
        return true;
    }
    if(!isvalid(i,j))
        return false;
    ans[i][j]=1;
    if(solvemaze(i+1,j)==true)
        return true;
    if(solvemaze(i,j+1)==true)
        return true;
    ans[i][j]=0;
    return false;
}
int main() 
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            ans[i][j]=0;
    solvemaze(0,0);
    return 0; 
} 