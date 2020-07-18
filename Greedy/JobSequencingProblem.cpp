// Link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0

// Given a set of n jobs where each job i has a deadline di >=1 and profit pi>=0. Only one job can be scheduled at a time. 
//Each job takes 1 unit of time to complete. We earn the profit if and only if the job
//is completed by its deadline. The task is to find the subset of jobs that maximizes profit.

// solution

#include<bits/stdc++.h>
using namespace std;
struct Job
{
    char id;
    int deadline;
    int profit;
};
bool comp(Job a,Job b)
{
    return a.profit>b.profit;
}
void printJobScheduling(Job arr[],int n)
{
    sort(arr,arr+n,comp);
    int result[n];
    bool remain[n]={false};
    for (int i=0;i<n;i++)
    {
        for (int j=min(n,arr[i].deadline)-1;j>=0;j--)
        {
            if(remain[j]==false)
            {
                remain[j]=true;
                result[j]=i;
                break;
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        if(remain[i])
            cout << arr[result[i]].id << " ";
    }
}
int main() 
{ 
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Following is maximum profit sequence of jobs:-"; 
    printJobScheduling(arr, n); 
    return 0; 
} 