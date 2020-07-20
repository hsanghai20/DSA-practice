// Link: https://leetcode.com/problems/n-queens/

// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

// Solution:
bool ispossible(int n,int row,int col,vector<vector<int>>& visited)
    {
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
            if(visited[i][j]==1)
                return false;
        for(int i=0;i<row;i++)
            if(visited[i][col]==1)
                return false;
        for(int i=row,j=col;i>=0&&j<n;i--,j++)
            if(visited[i][j]==1)
                return false;
        return true;
    }
    void queenplacement(int n,int row,vector<vector<int>>& visited,vector<vector<string>>& ans)
    {
        if(row==n)
        {
            vector<string> s;
            for(int i=0;i<n;i++)
            {
                string st="";
                for(int j=0;j<n;j++)
                {
                    if(visited[i][j]==0)
                        st+=".";
                    else
                        st+="Q";
                }
                s.push_back(st);
            }
            ans.push_back(s);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(ispossible(n,row,i,visited))
            {
                visited[row][i]=1;
                queenplacement(n,row+1,visited,ans);
                visited[row][i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> visited(n);
        vector<vector<string>> ans;
        for (int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                visited[i].push_back(0);
        queenplacement(n,0,visited,ans);
        return ans;
    }