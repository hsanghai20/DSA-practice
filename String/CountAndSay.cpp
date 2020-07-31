// Link: https://leetcode.com/problems/count-and-say/

// solution:
string countAndSay(int n) 
    {
        string s="1";
        if(n==1)
            return s;
        for(int i=2;i<=n;i++)
        {
            string temp="";
            int count=0;
            char curr=s[0];
            for(int j=0;j<s.length();j++)
            {
                if(curr==s[j])
                    count++;
                else
                {
                    temp+=count+'0';
                    temp+=curr;
                    count=1;
                    curr=s[j];
                }
            }
            temp+=count+'0';
            temp+=curr;
            // cout << temp << endl;
            s=temp;
        }
        return s;
    }