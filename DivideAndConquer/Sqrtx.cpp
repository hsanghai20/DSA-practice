// Link: https://leetcode.com/problems/sqrtx/

// Implement int sqrt(int x).

// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

// solution
int mySqrt(int x) {
        if(x==0)
            return 0;
        long long int start=1;
        long long int end=x;
        long long int ans=0;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(mid > x/mid)
                end=mid-1;
            else
            {
                if(mid+1 > x/(mid+1))
                    return mid;
                start=mid+1;
            }
        }
        return ans;
    }