// Link: https://leetcode.com/problems/factorial-trailing-zeroes/

// Count trailing zeros in factorial of a number 

// soln bcz only 5 and 2 make 10 2 are in large amount as compared to 5 so we just have to count no of 5 before no
int trailingZeroes(int n) {
        int ans=0;
        for (long long i=5;n/i>0;i*=5)
            ans+=n/i;
        return ans;
    }