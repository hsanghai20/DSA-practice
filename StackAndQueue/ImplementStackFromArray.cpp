#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000 
  
class Stack { 
    int top=-1; 
  
public: 
    int arr[MAX]; // Maximum size of Stack 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
};

bool Stack::push(int x)
{
    if(top>=MAX-1)
        return false;
    top++;
    arr[top]=x;
    return true;
}

int Stack::pop()
{
    if(top<0)
        return -1;
    int x= arr[top];
    top--;
    return x;
}

int Stack::peek()
{
    if(top<0)
        return -1;
    return arr[top];
}
bool Stack::isEmpty()
{
    if(top<0)
        return true;
    return false;
}
int main() 
{
    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack" << endl; 
    cout << s.peek() << " First Element in stack" << endl;
	return 0;
}