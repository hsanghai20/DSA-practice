// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool col0status=false,row0status=false;
        for (int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
                col0status=true;
            for (int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for (int i=n-1;i>=0;i--)
        {
            for (int j=m-1;j>=1;j--)
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            if(col0status==true)
                matrix[i][0]=0;
        }
    }