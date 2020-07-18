// Link: https://leetcode.com/problems/partition-equal-subset-sum/

// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets 
// such that the sum of elements in both subsets is equal.

// solution(backtracking) can be better solve by dp 
    bool ispossible(vector<int>& arr,int i,int sum)
    {
        if(i==arr.size() || sum<0)
            return false;
        if(sum==arr[i])
            return true;
        if(sum<arr[i])
            return false;
        return ispossible(arr,i+1,sum-arr[i]) || ispossible(arr,i+1,sum);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        sort(nums.rbegin(),nums.rend());//sort in dec order
        return ispossible(nums,0,sum/2);
    }