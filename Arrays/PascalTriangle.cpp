//Link : https://leetcode.com/problems/pascals-triangle/submissions/

// Make pascal triangle

void pascalrow(vector<vector<int>>& arr,int n)
    {
        for (int i=0;i<n;i++)
        {
            if(i==0 || i==n-1)
                arr[n-1].push_back(1);
            else
                arr[n-1].push_back(arr[n-2][i]+arr[n-2][i-1]);
        }
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr(numRows);
        for (int i=1;i<=numRows;i++)
        {
            pascalrow(arr,i);
        }
        return arr;
    }