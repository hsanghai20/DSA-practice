// Given arrival and departure times of all trains that reach a railway station, the task is to find
// the minimum number of platforms required for the railway station so that no train waits.
//We are given two arrays which represent arrival and departure times of trains that stop.

// solution
#include<bits/stdc++.h>
using namespace std;
int findPlatform(int arr[],int dep[],int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    int ans=0;
    int plat_req=1;
    int i=1,j=0;
    while(i<n&& j<n)
    {
        if(arr[i]<=dep[j])
        {
            plat_req++;
            i++;
        }
        else
        {
            plat_req--;
            j++;
        }
        ans=max(ans,plat_req);
    }
    return ans;
}
int main() 
{ 
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n); 
    return 0; 
} 