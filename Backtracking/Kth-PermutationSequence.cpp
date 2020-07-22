// Link: https://leetcode.com/problems/permutation-sequence/

// The set [1,2,3,...,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note:

// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.

// solution
 string getPermutation(int n, int k) {
        string s="";
        int fact[n+1];
        fact[0]=1;
        for(int i=1;i<=n;i++)
        {
            s+=i+'0';
            fact[i]=fact[i-1]*i;
        }
        string ans="";
        k--;
        for(int i=n-1;i>=0;i--)
        {
            int col=k/fact[i];
            k%= fact[i];
            ans+=s[col];
            s.erase(s.begin()+col);
        }
        return ans;
    }