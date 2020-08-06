// Link: https://leetcode.com/problems/word-break/

// solution:

    bool wordBreakHelper(string s, vector<string>& wordDict, string temp,map<string,bool>& mp){
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        if(s==temp)
            return true;
        if(temp.length()>s.length())
            return false;
        for(int i=0;i<temp.length();i++)
            if(temp[i]>s[i] || temp[i]!=s[i])
                return false;
        for(int i=0;i<wordDict.size();i++){
            mp[temp+wordDict[i]]=wordBreakHelper(s, wordDict, temp+wordDict[i],mp);
            if(mp[temp+wordDict[i]])
               return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool> mp;
        return wordBreakHelper(s, wordDict, "",mp);
    }
