// Link: https://leetcode.com/problems/counting-bits/

//Given a non negative integer number num. 
//For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

// solution:
vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if(num==0)
            return ans;
        ans.push_back(1);
        if(num==1)
            return ans;
        int ptr=1;
        int bit=2;
        for(int i=2;i<=num;i++)
        {
            if(i==bit)
            {
                ans.push_back(1);
                ptr=1;
                bit=bit<<1;
                continue;
            }
            ans.push_back(1+ans[ptr]);
            ptr++;
        }
        return ans;
    }