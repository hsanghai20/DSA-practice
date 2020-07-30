// Link: https://leetcode.com/problems/implement-strstr/

// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// solution:
int strStr(string haystack, string needle) {
        if(needle.length()==0)
            return 0;
        if(haystack.length()<needle.length())
            return -1;
        int ans=-1;
        for(int i=0;i<=haystack.length()-needle.length();i++)
        {
            string s=haystack.substr(i,needle.length());
            if(s==needle)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }