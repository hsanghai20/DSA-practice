//Link - https://leetcode.com/problems/find-all-duplicates-in-an-array/

 // Find all duplicates in o(1) space and o(n) time

 // method-1 best approach
 vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]>=0)
            {
                nums[abs(nums[i])-1]=-1*nums[abs(nums[i])-1];
            }
            else
            {
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }

// method-2 this approach is not that much better as it uses two for loop and upper one has 1 for loop
vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            else
                i++;
        }
        for (int i=0;i<n;i++)
        {
            if(nums[i]-1!=i)
                ans.push_back(nums[i]);
        }
        return ans;
    }
