// Link : https://leetcode.com/problems/single-element-in-a-sorted-array/

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

// Follow up: Your solution should run in O(log n) time and O(1) space.

// solution: 
int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start<end)
        {
            int mid=(start+end)/2;
            if((nums[mid]==nums[mid+1]&& mid%2==0) || (mid%2==1&&nums[mid]==nums[mid-1]))
                start=mid+1;
            else
               end=mid;
        }
        return nums[start];
    }