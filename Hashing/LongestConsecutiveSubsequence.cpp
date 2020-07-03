// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

//Your algorithm should run in O(n) complexity.

// solution (good question)
int longestConsecutive(vector<int>& nums) {
        if(!nums.size())
            return 0;
       unordered_set <int> s;
        for (int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        int ans=0;
        for (int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int currnum=nums[i];
                int sum=1;
                while(s.find(currnum+1)!=s.end())
                    sum++,currnum++;
                ans=max(ans,sum);
            }
        }
        return ans;
    }