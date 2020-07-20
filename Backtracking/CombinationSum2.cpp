// Link: https://leetcode.com/problems/combination-sum-ii/

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// solution
 void findallcombinations(vector<int>& candidates, int target,int ptr,vector<vector<int>>& ans,vector<int>& temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(ptr==candidates.size() || target<0)
            return;
        for(int i=ptr;i<candidates.size();i++)
        {
            if(i==ptr || candidates[i]!=candidates[i-1])
            {
                temp.push_back(candidates[i]);
                findallcombinations(candidates,target-candidates[i],i+1,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        findallcombinations(candidates,target,0,ans,temp);
        return ans;
    }