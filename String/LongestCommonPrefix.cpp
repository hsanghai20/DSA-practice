// Link: https://leetcode.com/problems/longest-common-prefix/

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// solution: (can also solve using binary search try to think)
string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return ""; 
        string ans="";
        int flag=0;
        for(int i=0;i<strs[0].length();i++)
        {
            for(int j=0;j<strs.size()-1;j++)
            {
                if(strs[j].length()<i)
                {
                    flag=1;
                    break;
                }
                if(strs[j][i]!=strs[j+1][i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
            ans+=strs[0][i];
        }
        return ans;
    }

