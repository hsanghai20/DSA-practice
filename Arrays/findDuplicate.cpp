// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
// find the duplicate one.

// function (best approach) known as Floyd's Tortoise and Hare (Cycle Detection)
    int findDuplicate(vector<int>& nums) {
        int slowptr=nums[0];
        int fastptr=nums[0];
        do{
            slowptr=nums[slowptr];
            fastptr=nums[nums[fastptr]];
        }while(fastptr!=slowptr);
        fastptr=nums[0];
        while(slowptr!=fastptr)
        {
            slowptr=nums[slowptr];
            fastptr=nums[fastptr];
        }
        return slowptr;
    }