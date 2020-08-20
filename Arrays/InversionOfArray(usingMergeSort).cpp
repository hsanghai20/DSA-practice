// Link: https://www.geeksforgeeks.org/counting-inversions/

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ulli;
using namespace std;
int ans=0;
void merge(int arr[],int temp[],int left,int mid,int right)
{
  int i=left;
  int j=mid;
  int k=left;
  while(i<mid&& j<=right)
  {
    if(arr[i]<=arr[j])
      temp[k++]=arr[i++];
    else
    {
      temp[k++]=arr[j++];
      ans+=mid-i;
    }
  }
  while(i<mid)
    temp[k++]=arr[i++];
  while(j<=right)
    temp[k++]=arr[j++];
  for(i=left;i<=right;i++)
    arr[i]=temp[i];
}
void mergesort(int arr[],int temp[],int left,int right,int n)
{
  // first method using recursion :

  if(left>=right)
    return;
  int mid=(left+right)/2;
    mergesort(arr,temp,left,mid,n);
    mergesort(arr,temp,mid+1,right,n); 
    merge(arr,temp,left,mid+1,right);

  // seccond method using iterative
  int i;
  for(i=2;i<=n;i*=2)
  {
    for(int j=0;j+i-1<n;j+=i)
    {
      int left=j;
      int right=i+j-1;
      int mid=(left+right)/2;
      merge(arr,temp,left,mid+1,right);
    }
  }
  if(i/2<n)
  {
    cout << "HEllo";
    merge(arr,temp,0,i/2,n-1);
  }
}
int main() {
	int n;
  cin >> n;
  int arr[n],temp[n];
  for(int i=0;i<n;i++)
    cin >> arr[i];
  mergesort(arr,temp,0,n-1,n);
  for(int i=0;i<n;i++)
    cout << arr[i] << " ";
  cout << endl;
  cout << ans << endl;
}