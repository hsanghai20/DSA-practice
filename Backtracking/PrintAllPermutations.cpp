// Link: https://leetcode.com/problems/permutations/

// Given a collection of distinct integers, return all possible permutations.

// solution
 void printallpermutations(vector<int>& nums,int ptr,vector<vector<int>>& ans)
    {
        if(ptr==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ptr;i<nums.size();i++)
        {
            swap(nums[ptr],nums[i]);
            printallpermutations(nums,ptr+1,ans);
            swap(nums[ptr],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        printallpermutations(nums,0,ans);
        return ans;
    }