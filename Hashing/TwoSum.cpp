// Link: https://leetcode.com/problems/two-sum/

//Given an array of integers, return indices of the two numbers such that they add up to a specific target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

// solution 
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for (int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            m[nums[i]]=i;
        }
        return ans;
    }