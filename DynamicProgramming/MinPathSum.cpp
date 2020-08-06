// Link: https://leetcode.com/problems/minimum-path-sum/

// solution:
    int minPathSum(vector<vector<int>>& grid)
    {
        if(grid.size()==0 || grid[0].size()==0)
            return 0;
        int dp[grid.size()][grid[0].size()];
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=grid[i][j];
                else if(i==0)
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                else if(j==0)
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
