// Link: https://leetcode.com/problems/combination-sum/

// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// solution
 void findallcombinations(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& ans,int ptr)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(ptr==candidates.size() || target<0)
            return;
        temp.push_back(candidates[ptr]);
        findallcombinations(candidates,target-candidates[ptr],temp,ans,ptr);
        temp.pop_back();
        findallcombinations(candidates,target,temp,ans,ptr+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findallcombinations(candidates,target,temp,ans,0);
        return ans;
    }