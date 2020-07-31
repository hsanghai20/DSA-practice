// Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

// solution: 
    int minInsertions(string s) {
        // basically we have to find longest palindromic subsequence
        int n=s.length();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i+1;j++)
            {
                if(i==1)
                    dp[i][j]=1;
                else
                {
                     if(s[j-1]==s[j+i-2])
                        dp[i][j]=2+dp[i-2][j+1];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j+1]);
                }        
            }
        }
        return n-dp[n][1];
    }