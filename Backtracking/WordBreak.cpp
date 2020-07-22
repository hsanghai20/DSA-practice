// Link: https://leetcode.com/problems/word-break/

// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note:

// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.

                         //*** for solving this problem we have to use dp ****//
                         
// solution (recursion but this will got tle)
bool findword(string s,set<string> word,int ptr)
    {
        if(ptr==s.size())
            return true;
        string st="";
        for(int i=ptr;i<s.size();i++)
        {
            st+=s[i];
            if(word.find(st)!=word.end())
                if(findword(s,word,i+1)) return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word;
        for(int i=0;i<wordDict.size();i++)
            word.insert(wordDict[i]);
        return findword(s,word,0);
    }

// solution (recursion but this also got tle)
bool findword(string s,vector<string>& wordDict,string temp)
    {
        if(s==temp)
            return true;
        if(temp.length()>s.length())
            return false;
        for(int i=0;i<temp.length();i++)
        {
            if(s[i]!=temp[i])
                return false;
        }
        for(int i=0;i<wordDict.size();i++)
        {
            if(findword(s,wordDict,temp+wordDict[i]))
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string temp="";
        return findword(s,wordDict,temp);
    }