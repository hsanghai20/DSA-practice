// Link: https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0

// Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of 
//the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000}
// valued coins/notes, what is the minimum number of coins and/or notes needed to make the change?

// solution
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int coins[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };// only valid for indian currency
    int n=9;
    int v;
    cin >> v;
    int ans=0;
    for (int i=n-1;i>=0;i--)
    {
        if(v>=coins[i])
        {
            ans+=v/coins[i];
            v=v%coins[i];
        }
    }
    cout << ans << endl;
    return 0;
}