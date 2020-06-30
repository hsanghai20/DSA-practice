// Given a collection of intervals, merge all overlapping intervals.

// method
vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector <vector<int>> ans;
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(),intervals.end());
        vector <int> interval;
        interval.push_back(intervals[0][0]);
        interval.push_back(intervals[0][1]);
        ans.push_back(interval);
        int x=0;
        for (int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>ans[x][1])
            {
                x++;
                vector<int> intervaaal;
                intervaaal.push_back(intervals[i][0]);
                intervaaal.push_back(intervals[i][1]);
                ans.push_back(intervaaal);
            }
            else
            {
                ans[x][1]=max(intervals[i][1],ans[x][1]);
            }
        }
        return ans;
    }