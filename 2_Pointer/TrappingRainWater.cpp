// Link: https://leetcode.com/problems/trapping-rain-water/

// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
//compute how much water it is able to trap after raining.

// solution-1(using o(n) space)
int trap(vector<int>& height) 
    {
        int maxuntil[height.size()];
        int ma=0;
        for (int i=height.size()-1;i>=0;i--)
        {
            ma=max(ma,height[i]);
            maxuntil[i]=ma;
        }
        ma=0;
        int ans=0;
        for (int i=0;i<height.size();i++)
        {
            ma=max(ma,height[i]);
            ans+=min(ma,maxuntil[i])-height[i];
        }
        return ans;
    }

// solution -2(in one pass and o(1) space)
int trap(vector<int>& height) 
    {
        int leftmax=0,rightmax=0;
        int ans=0;
        int left=0,right=height.size()-1;
        while(left<right)
        {
            if(height[right]>height[left])
            {
                height[left]>=leftmax?(leftmax=height[left]):ans+=(leftmax-height[left]);
                left++;
            }
            else
            {
                height[right]>=rightmax?(rightmax=height[right]):ans+=(rightmax-height[right]);
                right--;
            }
        }
        return ans;
    }