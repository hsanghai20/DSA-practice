// Link: https://leetcode.com/problems/valid-anagram/

//  
bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(m.find(t[i])==m.end() || m.find(t[i])->second==0)
                return false;
            m[t[i]]--;
        }
        return true;
    }