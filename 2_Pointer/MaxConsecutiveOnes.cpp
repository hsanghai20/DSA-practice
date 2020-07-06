//Link: https://leetcode.com/problems/max-consecutive-ones/

// Given a binary array, find the maximum number of consecutive 1s in this array.

// method-1(two pointer)
int findMaxConsecutiveOnes(vector<int>& nums) {
        int start=-1,end=-1;
        int len=0;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                if(start==-1)
                    start=i,len=max(len,1);
                else
                {
                    end=i;
                    len=max(len,end-start+1);
                }
            }
            else
            {
                start=-1;
                end=-1;
            }
        }
        return len;
    }


    // method - 2(track of sum)
     int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,sum=0;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                ans=max(++sum,ans);   
            else
                sum=0;
        }
        return ans;
    }
