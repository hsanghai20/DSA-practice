// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

// solution (very good ques)
// remember always if we find next max or min or something corrosponding every element min and max try to use stack
int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0)
            return 0;
        if(n==1)
            return heights[0];
        int max_area=0;
        int curr_area=0;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            int temp=heights[i];
            if(s.empty() || temp>=heights[s.top()])
                s.push(i);
            else
            {
                while(!s.empty() && temp<heights[s.top()])
                {
                    int curr=heights[s.top()];
                    s.pop();
                    if(s.empty())
                    {
                        max_area=max(max_area,curr*i);
                    }
                    else
                    {
                        curr_area=curr*(i-s.top()-1);
                        max_area=max(max_area,curr_area);
                    }
                }
                s.push(i);
            }
        }
        while(!s.empty())
        {
            int curr=heights[s.top()];
            s.pop();
            if(s.empty())
            {
                max_area=max(max_area,curr*n);
            }
            else
            {
                curr_area=curr*(n-s.top()-1);
                max_area=max(max_area,curr_area);
            }
        }
        return max_area;
    }