// Link: https://leetcode.com/problems/longest-palindromic-substring/

// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// solution(recursion this will not pass we have to do this using dp)
 bool ispalindrome(string s)
    {
        string temp=s;
        reverse(s.begin(),s.end());
        return (s==temp);
    }
    void longpalindrome(string s,int ptr,string& temp,string str)
    {
        if(str!="")
        {
            if(temp.length()<str.length())
                temp=str;
        }
        if(ptr==s.length())
            return;
        str="";
        for(int i=ptr;i<s.length();i++)
        {
            str+=s[i];
            if(ispalindrome(str))
            {
                longpalindrome(s,i+1,temp,str);
            }
        }
        
    }
    string longestPalindrome(string s) {
        string temp="";
        longpalindrome(s,0,temp,"");
        return temp;
    }

// solution (dp)(using dp to store position that from this element to this element is this a palindrome)
string longestPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return "";
        int dp[n][n];
        for(int i=0;i<s.length();i++)
            for(int j=0;j<s.length();j++)
                dp[i][j]=-1;
        for(int i=0;i<s.length();i++)
            dp[i][i]=1;
        for(int i=0;i<s.length();i++)
        {
            if(i+1<s.length())
            {
                dp[i][i+1]=(s[i]==s[i+1])?1:0;
            }
        }
        for(int i=s.length()-1;i>=0;i--)
        {
            for(int j=i+2;j<s.length();j++)
            {
                // cout << i << j << endl;
                if(dp[i+1][j-1]==1)
                    if(s[i]==s[j])
                        dp[i][j]=1;
                else
                    dp[i][j]=0;
            }
        }
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(dp[i][j]==1)
                {
                    if(ans.length()<j-i+1)
                    {
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }

// solution (mancher's good algorithm)
string longestPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return "";
        // manchers algo
        string str="#";
        for(int i=0;i<n;i++)
        {
            str+=s[i];
            str+='#';
        }
        int arr[2*n+1];
        int end=0;
        int mir=0;
        // cout << str << endl;
        for(int i=0;i<2*n+1;i++)
        {
            if(i<mir)
            {
                arr[i]=min(end-i,arr[mir-(i-mir)]);
            }
            else
            {
                arr[i]=0;
            }
            while(i+arr[i]+1<2*n+1 && i-arr[i]-1>=0 && str[i+arr[i]+1]==str[i-arr[i]-1])
                arr[i]++;
            if(i+arr[i]>end)
            {
                end=i+arr[i];
                mir=i;
            }
            // cout << arr[i] << endl;
        }
        int ma=0;
        int index=-1;
        for(int i=0;i<2*n+1;i++)
        {
            if(ma<arr[i])
            {
                ma=arr[i];
                index=i;
            }
        }
        string q="";
        for(int i=index-ma;i<=index+ma;i++)
        {
            if(str[i]!='#')
                q+=str[i];
        }
        return q;
    }
