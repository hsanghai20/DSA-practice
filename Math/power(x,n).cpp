// Link:   https://leetcode.com/problems/powx-n/

// Implement pow(x, n), which calculates x raised to the power n (x^n) in logn time.

// solution
double power(double x,int n){
        if(n==0)
            return 1;
        if(n%2==0)
            return power(x*x,n/2);
        else
            return x*power(x*x,n/2);
    }
    double myPow(double x, int n) {
        double ans= power(x,n);
        if(n<0)
            ans=1/ans;
        return ans;
    }

// method-2 (good approach by bits)
double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0) {
        n = -n;
        x = 1/x;
    }
    double ans = 1;
    while(n>0){
        if(n&1) ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

