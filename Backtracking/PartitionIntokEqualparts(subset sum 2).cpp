// Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

// Given an array of integers nums and a positive integer k, find whether it's possible to divide this array 
// into k non-empty subsets whose sums are all equal.

// solution(can be solved using more efficient approach dp)
 bool ispossible(vector<int>& nums,int k,int ptr,int sum,int target,bool visited[])
    {
        if(k==1)
            return true;
        if(sum==0 && ptr!=nums.size())
            return ispossible(nums,k-1,0,target,target,visited);
        for(int i=ptr;i<nums.size();i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                if(ispossible(nums,k,i+1,sum-nums[i],target,visited))return true;
                // backtrack
                visited[i]=false;
            }
        }
        return false;
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%k!=0)
            return false;
        bool visited[n];
        for(int i=0;i<n;i++)
            visited[i]=false;
        return ispossible(nums,k,0,sum/k,sum/k,visited);
    }