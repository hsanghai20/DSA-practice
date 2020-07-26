// Link: https://leetcode.com/problems/implement-stack-using-queues/

// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.

// solution: 
class MyStack {
public:
    /** Initialize your data structure here. */
    int last;
    queue<int> q;
    MyStack() {
        last=-1;
    }
    
    /** Push element x onto stack. */
    void push(int x) 
    {
        q.push(x);
        last=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> q2;
        while(q.size()!=1)
        {
            int x=q.front();
            q.pop();
            last=x;
            q2.push(x);
        }
        int re=q.front();
        q.swap(q2);
        return re;
        
    }
    
    /** Get the top element. */
    int top() {
        return last;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.size()==0)
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */