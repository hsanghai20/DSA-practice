// Link: https://www.interviewbit.com/problems/matrix-median/

// Given a matrix of integers A of size N x M in which each row is sorted.

// Find an return the overall median of the matrix A.

// Note: No extra memory is allowed.

// Note: Rows are numbered from top to bottom and columns are numbered from left to right.

// solution:
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100; 
int upper_bound(int m[],int n,int no)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(m[mid]>no)
            end=mid;
        else
            start=mid+1;
    }
    return start;
}
// lower bound just for refrence not needed
int lower_bound(int m[],int n,int no)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(m[mid]<no)
            start=mid+1;
        else
            end=mid;
    }
    return start;
}
int binarymedian(int m[][MAX],int r,int c)
{
    int mi=INT_MAX;
    int ma=INT_MIN;
    for(int i=0;i<r;i++)
    {
        mi=min(mi,m[i][0]);
        ma=max(ma,m[i][c-1]);
    }
    int start=mi,end=ma;
    int no=(r*c+1)/2;
    while(start<end)
    {
        int mid=(start+end)/2;
        int count=0;
        for(int i=0;i<r;i++)
            count+=upper_bound(m[i],c,mid);
        if(count>=no)
            end=mid;
        else
            start=mid+1;
    }
    return start;
}
int main(){
    int r = 3, c = 3; 
    int m[][MAX]= { {1,3,5}, {2,6,9}, {3,6,9} }; 
    cout << "Median is " << binarymedian(m, r, c) << endl; 
    return 0; 
}