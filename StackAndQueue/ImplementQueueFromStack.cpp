// Link: https://leetcode.com/problems/implement-queue-using-stacks/

// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.

// solution: 
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    MyQueue() {
        stack<int> s1;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> s2;
        while(s1.size()!=0)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()!=0)
            s1.push(s2.top()),s2.pop();
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x=s1.top();
        s1.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.size()==0)
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */