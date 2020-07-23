// Link: https://leetcode.com/problems/search-a-2d-matrix/

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// solution:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        int start=0;
        int end=matrix.size()*matrix[0].size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]==target)
                return true;
            else if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]<target)
                start=mid+1;
            else 
                end=mid-1;
        }
        return false;
    }