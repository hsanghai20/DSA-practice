// Link: https://leetcode.com/problems/partition-equal-subset-sum/

// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets 
// such that the sum of elements in both subsets is equal.

// solution(backtracking) can be better solve by dp 
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            sum+= nums[i];
        }
        if(sum%2) return false;
        sum /= 2;
        sort(nums.rbegin(),nums.rend());
        return helper(nums, sum, 0);
    }
    bool helper(vector<int>& nums, int sum, int index){
        if(sum == nums[index]) return true;
        if(sum < nums[index]) return false;
        return helper(nums,sum-nums[index],index+1) || helper(nums,sum,index+1);
    }