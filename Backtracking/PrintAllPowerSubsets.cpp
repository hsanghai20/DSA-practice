 // Link: https://leetcode.com/problems/subsets-ii/

 // Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.

// solution(backtracking)
 
 void findsubsets(vector<vector<int>>& ans,vector<int>temp,vector<int> nums,int start)
    {
        ans.push_back(temp);
        for (int i=start;i<nums.size();i++)
        {
            if(i==start || nums[i]!=nums[i-1])
            {
                temp.push_back(nums[i]);
                findsubsets(ans,temp,nums,i+1);
                // backtraking
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        findsubsets(ans,temp,nums,0);
        return ans;
    }