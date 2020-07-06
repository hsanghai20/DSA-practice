// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

//Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// solution
int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int ans=1;
        int start=0;
        int end=1;
        while(end!=nums.size())
        {
            if(nums[start]!=nums[end])
            {
                ans++;
                nums[++start]=nums[end];
            }
            end++;
        }
        return ans;
    }