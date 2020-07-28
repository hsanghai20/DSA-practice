// Link: https://leetcode.com/problems/rotting-oranges/

// In a given grid, each cell can have one of three values:

// the value 0 representing an empty cell;
// the value 1 representing a fresh orange;
// the value 2 representing a rotten orange.
// Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

// solution(good dfs problem):
    bool check(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        return (i>=0 && j>=0 && i<n && j<m && grid[i][j]==1);
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        while(fresh>0 && !q.empty())
        {
            ans++;
            int x=q.size();
            // cout << ans << " " << x <<endl;
            for(int r=0;r<x;r++)
            {
                // cout << ans << endl;
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                cout << x << " " << i << " " << j << " " << fresh << endl ;
                if(check(i+1,j,n,m,grid))
                {
                    grid[i+1][j]=2;
                    q.push(make_pair(i+1,j));
                    fresh--;
                }
                if(check(i-1,j,n,m,grid))
                {
                    grid[i-1][j]=2;
                    q.push(make_pair(i-1,j));
                    fresh--;
                }
                if(check(i,j+1,n,m,grid))
                {
                    grid[i][j+1]=2;
                    q.push(make_pair(i,j+1));
                    fresh--;
                }
                if(check(i,j-1,n,m,grid))
                {
                    grid[i][j-1]=2;
                    q.push(make_pair(i,j-1));
                    fresh--;
                }
            }
        }
        if(fresh>0)
            return -1;
        return ans;
    }

