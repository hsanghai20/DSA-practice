// Link: https://practice.geeksforgeeks.org/problems/rod-cutting/0

// solution:
#include <bits/stdc++.h> 
using namespace std; 
int cutRod(int price[],int n)
{
  int dp[n];
  dp[0]=price[0];
  for(int i=1;i<=n;i++)
  {
    int ma=price[i];
    for(int j=0;j<=i/2;j++)
    {
      ma=max(ma,dp[i-j-1]+dp[j]);
    }
    dp[i]=ma;
  }
  return dp[n-1];
}
int main() 
{ 
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    printf("Maximum Obtainable Value is %d", cutRod(arr, size)); 
    return 0; 
} 