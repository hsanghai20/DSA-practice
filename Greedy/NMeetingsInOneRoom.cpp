// Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

// Same goes for the actvivity selection problems //

// There is one meeting room in a firm. 
//There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is finish time of meeting i.
// The task is to find the maximum number of meetings that can be accommodated in the meeting room

// solution
#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    int n;
    cin >> n;
    vector <pair<int,int>> arr;
    for (int i=0;i<n;i++)
    {
        int start,end;
        cin >> start >> end;
        arr.push_back(make_pair(start,end));
    } 
    sort(arr.begin(),arr.end(),comp);
    vector<pair<int,int>> ans;
    ans.push_back(arr[0]);
    int point=0;
    for (int i=1;i<n;i++)
    {
        if(arr[i].first>=arr[point].second)
        {
            ans.push_back(arr[i]);
            point=i;
        }
    }
    for (int i=0;i<ans.size();i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
} 