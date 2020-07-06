// Link : https://leetcode.com/problems/3sum/

//Given an array nums of n integers, are there elements a, b, c in nums 
//such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// solution
 vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();i++)
        {
            int target=-nums[i];
            int start=i+1;
            int end=nums.size()-1;
            while(start<end)
            {
                int sum=nums[start]+nums[end];
                if(sum>target)
                    end--;
                else if(sum<target)
                    start++;
                else
                {
                    vector <int> a(3,0);
                    a[0]=-target;
                    a[1]=nums[start];
                    a[2]=nums[end];
                    res.push_back(a);
                    while(start<end && a[1]==nums[start])start++;
                    while(start<end && a[2]==nums[end])end--;
                }
            }
            while(i+1<nums.size() && nums[i+1]==nums[i])i++;
        }
        return res;
    }