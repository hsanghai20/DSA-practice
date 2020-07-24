// Link: https://www.geeksforgeeks.org/find-significant-set-bit-number/

// very easy ques
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x=log2(n);
    cout << "MSB corrosponding no is " << pow(2,x);
    return 0; 
}