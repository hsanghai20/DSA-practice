// Link: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

// solution: 
#include<bits/stdc++.h>
using namespace std;
// using KMP algorithm
void search(string pat,string txt)
{
  int lps[pat.length()];
  int i=0;
  int j=0;
  while(j<pat.length())
  {
    if(j==0)
      lps[j]=0;
    else if(pat[j]==pat[i])
    {
      i++;
      lps[j]=i;
    }
    else
    {
      i=0;
      lps[j]=0; 
    }
    j++;
  }
  j=0;
  i=0;
  while(i<txt.length())
  {
    if(pat[j]==txt[i])
    {
      j++;
      i++;
    }
    if(j==pat.length())
    {
      cout << i-j << " ";
      j=lps[j-1];
    }
    else if(i<txt.length() && pat[j]!=txt[i])
    {
      if(j==0)
        i++;
      else
        j=lps[j-1];
    }
  }
}
int main()
{
  string txt= "ABABABABAAAAAABAA";
  string pat= "ABA";
  search(pat,txt);
}