// LInk: https://leetcode.com/problems/subsets/

// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Solution(bit manupulation good approach something new)
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        long long int x= pow(2,nums.size());
        for(long long int i=0;i<x;i++)
        {
            vector<int> temp;
            long long int t=i;
            int ptr=0;
            while(t!=0)
            {
                if(t%2==1)
                    temp.push_back(nums[ptr]);
                t/=2;
                ptr++;
            }
            ans.push_back(temp);
        }
        return ans;
    }

// Solution(backtracking)
void makeallpowerset(vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans,int ptr)
    {
        ans.push_back(temp);
        for(int i=ptr;i<nums.size();i++)
        {
            if(i==ptr || nums[i]!=nums[i-1])
            {
                temp.push_back(nums[i]);
                makeallpowerset(nums,temp,ans,i+1);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        makeallpowerset(nums,temp,ans,0);
        return ans;
    }