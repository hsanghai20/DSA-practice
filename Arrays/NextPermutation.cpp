//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//The replacement must be in-place and use only constant extra memory.

// method- 1
 void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int store=-1;
        for (int i=n-1;i>=1;i--)
        {
            if(nums[i]>nums[i-1])
            {
                store=i;
                break;
            }
        }
        if(store==-1)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        sort(nums.begin()+store,nums.end());
        
        for (int i=store;i<n;i++)
        {
            if(nums[store-1]<nums[i])
            {
                swap(nums[store-1],nums[i]);
                break;
            }
        }
    }

// or use direct fnc from STL library
next_permutation(arr.begin(), arr.end());
// it returns true if able to arrange else return false.


