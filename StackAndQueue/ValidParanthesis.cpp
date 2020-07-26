// Link: https://leetcode.com/problems/valid-parentheses/

// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// solution: 
bool isValid(string s) {
        stack<char> ans;
        int i;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='[' || s[i]=='{' || s[i]=='(')
                ans.push(s[i]);
            else if(ans.size()!=0 && ((s[i]=='}' && ans.top()=='{') || (s[i]==']' && ans.top()=='[') || (s[i]==')' && ans.top()=='(') ))
            {
                ans.pop();
            }
            else 
                break;
        }
        if(ans.size()!=0 || i!=s.length())
            return false;
        return true;
    }