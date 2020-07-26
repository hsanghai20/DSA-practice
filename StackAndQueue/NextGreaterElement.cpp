// Link: https://leetcode.com/problems/next-greater-element-i/

// You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2.
// Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
// If it does not exist, output -1 for this number.

// solution:-
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++)
        {
            while(!s.empty() && s.top()<nums2[i])
            {
                int x=s.top();
                s.pop();
                m[x]=nums2[i];
            }
            s.push(nums2[i]);
        }
        while(!s.empty())
        {
            int x=s.top();
            s.pop();
            m[x]=-1;
        }
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }