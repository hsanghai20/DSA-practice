// Link: https://leetcode.com/problems/longest-common-subsequence/

// solution:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int len=0;
        int dp[text1.length()+1][text2.length()+1];
        for(int i=0;i<=text1.length();i++)
            for(int j=0;j<=text2.length();j++)
                dp[i][j]=0;
        for(int i=1;i<=text1.length();i++)
        {
            len++;
            for(int j=1;j<=text2.length();j++)
            {
                if(text1[i-1]==text2[j-1] && dp[i-1][j]!=len && dp[i][j-1]!=len)
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
