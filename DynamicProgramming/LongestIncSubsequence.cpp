// Link: https://leetcode.com/problems/longest-increasing-subsequence/

// solution(o(n2))
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int ans=1;
        int arr[nums.size()];
        for(int i=0;i<nums.size();i++)
            arr[i]=1;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    arr[i]=max(arr[j]+1,arr[i]);
                    ans=max(ans,arr[i]);
                }
            }
        
        }
        return ans;
    }