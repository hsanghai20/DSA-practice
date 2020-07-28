// Link:https://leetcode.com/problems/sliding-window-maximum/

// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. 
// Each time the sliding window moves right by one position. Return the max sliding window.

// solution:
typedef pair<int,int> pi;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pi> pq;
        vector<int> ans;
        for(int i=0;i<k-1;i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        for(int i=k-1;i<nums.size();i++)
        {
            pq.push(make_pair(nums[i],i));
            while(pq.top().second<=i-k)
                pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }