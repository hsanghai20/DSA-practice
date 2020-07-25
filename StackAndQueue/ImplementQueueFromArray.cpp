#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000 
  
class Queue { 
    int front=0;
    int rear=0; 
  
public: 
    int arr[MAX]; // Maximum size of Stack 
    bool enqueue(int x); 
    int dequeue(); 
    int queuefirst(); 
    bool isEmpty(); 
};

bool Queue::enqueue(int x)
{
    if(rear>=MAX)
        return false;
    arr[rear]=x;
    rear++;
    return true;
}

int Queue::dequeue()
{
    if(front==rear)
        return -1;
    int x=arr[0];
    for(int i=1;i<rear;i++)
        arr[i-1]=arr[i];
    rear--;
    return x;
}

int Queue::queuefirst()
{
    if(front==rear)
        return -1;
    return arr[front];
}
bool Queue::isEmpty()
{
    if(front==rear)
        return true;
    return false;
}
int main() 
{
    class Queue q; 
    q.enqueue(10); 
    q.enqueue(20); 
    q.enqueue(30); 
    cout << q.dequeue() << " Popped from Queue" << endl; 
    cout << q.dequeue() << " Popped from Queue" << endl;
    cout << q.dequeue() << " Popped from Queue" << endl;
    cout << q.dequeue() << " Popped from Queue" << endl;
    q.enqueue(10); 
    q.enqueue(20); 
    q.enqueue(30); 
    cout << q.queuefirst() << " First Element in Queue" << endl;
	return 0;
}