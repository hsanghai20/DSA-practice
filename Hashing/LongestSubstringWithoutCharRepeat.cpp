// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Given a string, find the length of the longest substring without repeating characters.

// solution
 int lengthOfLongestSubstring(string s) {
        int start=-1,end=0,ans=0;
        unordered_map <int,int> m;
        while(end<s.length())
        {
            if(m.find(s[end])!=m.end())
                start=max(start,m[s[end]]);
            m[s[end]]=end;
            ans=max(ans,end-start);
            end++;
        }
        return ans;
    }