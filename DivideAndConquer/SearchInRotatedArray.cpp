// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).

// solution: 
int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>=nums[0])
            {
                // mid ke pehle tak sorted hai
                if(target<nums[mid] && target>=nums[0])
                    end=mid-1;
                else
                    start=mid+1;
            }
            else
            {
                if(target>nums[mid]&& target<=nums[n-1])
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return -1;
    }