// Link: https://leetcode.com/problems/reverse-words-in-a-string/

// Given an input string, reverse the string word by word.

// solution: 
string reverseWords(string s) {
        string ans="";
        int start=0;
        while(start<s.length())
        {
            if(s[start]!=' ')
                break;
            start++;
        }
        int end=s.length()-1;
        while(end>=0)
        {
            if(s[end]!=' ')
                break;
            end--;
        }
        for(int i=end;i>=start;i--)
        {
            if(s[i]==' ' && s[i+1]==' ')
                continue;
            ans+=s[i];
        }
        string finalans="";
        string l="";
        // cout << ans << endl;
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]==' ')
            {
                reverse(l.begin(),l.end());
                if(finalans=="")
                    finalans+=l;
                else
                {
                    finalans+=' ';
                    finalans+=l;
                }
                l="";
            }
            else
                l+=ans[i];
        }
        // cout << l.length() << endl;
        if(l!="")
        {
            reverse(l.begin(),l.end());
            if(finalans=="")
                finalans+=l;
            else
            {
                finalans+=' ';
                finalans+=l;
            }
        }
        return finalans;
    }
    