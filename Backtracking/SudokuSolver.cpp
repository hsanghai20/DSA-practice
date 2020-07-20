// Link: https://leetcode.com/problems/valid-sudoku/

// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

  // 1.Each row must contain the digits 1-9 without repetition.
  // 2.Each column must contain the digits 1-9 without repetition.
  // 3.Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

  // solution
    bool isrowpossible(vector<vector<char>>& board,int row,int no)
    {
        // unordered_set<char> s;
        for(int i=0;i<9;i++)
            if(no+'0'==board[row][i])
                return false;
        return true;
    }
    bool iscolpossible(vector<vector<char>>& board,int col,int no)
    {
         for(int i=0;i<9;i++)
            if(no+'0'==board[i][col])
                return false;
        return true; 
    }
    bool isboxpossible(vector<vector<char>>& board,int row,int col,int no)
    {
        int x=row/3;
        int y=col/3;
        for(int i=3*x;i<3*x+3;i++)
        {
            for(int j=3*y;j<3*y+3;j++)
            {
                if(no+'0'==board[i][j])
                    return false;
            }
        }
        return true;
    }
    bool Sudoku(vector<vector<char>>& board,int row,int col)
    {
        if(row==9)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
            return true;
        }    
        else if(col==9)
            return Sudoku(board,row+1,0);
        else if(board[row][col]!='.')
        {
            char c=board[row][col];
            board[row][col]='.';
            if(isrowpossible(board,row,c-'0')&&iscolpossible(board,col,c-'0')&&isboxpossible(board,row,col,c-'0'))
            {
                board[row][col]=c;
                return Sudoku(board,row,col+1);    
            }
            else
            {
                board[row][col]=c;
                return false;
            }
        }
        for(int i=1;i<=9;i++)
        {
            if(isrowpossible(board,row,i)&&iscolpossible(board,col,i)&&isboxpossible(board,row,col,i))
            {
                board[row][col]=i+'0';
                if(Sudoku(board,row,col+1))return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return Sudoku(board,0,0);
    }