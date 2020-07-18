// Link: https://practice.geeksforgeeks.org/problems/gcd-of-two-numbers/0

// GCD of two no by Euclidean algo

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}