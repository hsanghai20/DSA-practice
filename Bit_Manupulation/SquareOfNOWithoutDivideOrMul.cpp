// Link: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/

// Solution:
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x=n;
    int ans=0;
    while(x!=0)
    {
         int t=(x&1);
         if(t==1)
             ans+=n;
         n=n<<1;
         x=x>>1;
    //     // cout << x << " " << n << endl;
    }
    cout << ans << endl;
}