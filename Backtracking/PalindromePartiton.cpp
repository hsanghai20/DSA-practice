// Link: https://leetcode.com/problems/palindrome-partitioning/

// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// solution:
bool ispalindrome(string s)
    {
        for(int i=0;i<s.length()/2;i++)
            if(s[i]!=s[s.length()-1-i])
                return false;
        return true;
    }
    void allpalindrome(string s,vector<vector<string>>& ans,vector<string>& temp,int ptr)
    {
        if(ptr==s.length())
        {
            ans.push_back(temp);
            return;
        }
        string str="";
        for(int i=ptr;i<s.length();i++)
        {
            str+=s[i];
            if(ispalindrome(str))
            {
                temp.push_back(str);
                allpalindrome(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        allpalindrome(s,ans,temp,0);
        return ans;
    }