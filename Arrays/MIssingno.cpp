//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
//find the one that is missing from the array.

// Method (XOR)
int missingNumber(vector<int>& nums) {
        int ans=0;
        for (int i=0;i<nums.size();i++)
        {
            ans^=nums[i];
            ans^=i;
        }
        ans=ans^nums.size();
        return ans;
    }

// method of sum
int missingNumber(vector<int>& nums) {
        int ans=(nums.size()*(nums.size()+1))/2;
        for (int i=0;i<nums.size();i++)
            ans-=nums[i];
        return ans;
    }