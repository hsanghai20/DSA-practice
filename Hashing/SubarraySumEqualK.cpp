// Link: https://leetcode.com/problems/subarray-sum-equals-k/

//Given an array of integers and an integer k, 
//you need to find the total number of continuous subarrays whose sum equals to k.

// solution
 int subarraySum(vector<int>& nums, int k)
    {
        if(!nums.size())
            return 0;
        unordered_map <int,int> m;
        int ans=0;
        int sum=0;
        m[0]=1;
        for (int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(m.find(sum-k)!=m.end())
                ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }