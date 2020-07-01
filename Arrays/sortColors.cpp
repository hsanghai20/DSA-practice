//Link : https://leetcode.com/problems/sort-colors/

//Sort an array of 0’s 1’s 2’s without using extra space or sorting algo 
// method - 1
void sortColors(int A[], int n) {
    int n0 = -1, n1 = -1, n2 = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) 
        {
            A[++n2] = 2; A[++n1] = 1; A[++n0] = 0;
        }
        else if (A[i] == 1) 
        {
            A[++n2] = 2; A[++n1] = 1;
        }
        else if (A[i] == 2) 
        {
            A[++n2] = 2;
        }
    }
}

// method -2 of swapping(known as sort 3 colors)
void sortColors(vector<int>& nums) {
        int redptr=0,blueptr=nums.size()-1;
        for (int i=0;i<=blueptr;i++)
        {
            if(nums[i]==0 && i!=redptr)
                swap(nums[i--],nums[redptr++]);
            else if(nums[i]==2 && i!=blueptr)
                swap(nums[i--],nums[blueptr--]);
        }
    }