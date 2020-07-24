// Link:https://leetcode.com/problems/divide-two-integers/

// Solution:
int divide(int dividend, int divisor) 
    {
        bool neg=((dividend>0 && divisor<0)||(dividend<0&& divisor>0))?true:false;
        long long divid=abs(dividend);
        divisor=abs(divisor);
        long long x=1;
        long long sub=divisor;
        long long ans=0;
        while(divid>=divisor)
        {
            if(divid>=sub)
            {
                divid-=sub;
                ans+=x;
                x=x<<1;
                sub=sub<<1;
            }
            else
            {
                sub=sub>>1;
                x=x>>1;
            }
        }
        if(neg)
            ans=-ans;
        if(ans<INT_MIN || ans>INT_MAX)
            return INT_MAX;
        return ans;
    }