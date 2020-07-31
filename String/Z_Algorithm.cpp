// Link: https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

// solution: 
#include<bits/stdc++.h>
using namespace std;
// using Z algorithm or LCP
void search(string s,int no)
{
  int L=0,R=0;
  int Zarray[s.length()];
  Zarray[0]=-1;
  int n=s.length();
  for(int i=1;i<s.length();i++)
  {
    int x;
    if(i>=R)
    {
      x=0;
    }
    else
    {
      x=min(R-i+1,Zarray[i-L]);
    }
    while(i+x<n && s[i+x]==s[x])
      x++;
    Zarray[i]=x;
    if(i+x>R)
    {
      L=i;
      R=i+x;
    }
  }
  for(int i=0;i<n;i++)
  {
    if(Zarray[i]==no)
    {
      cout << i-(no+1) << " ";
    }
  }
}
int main()
{
  string txt= "ABAAABABAAAAAABAA";
  string pat= "ABA";
  string s="";
  s+=pat;
  s+='$';
  s+=txt;
  search(s,pat.length());
}