// Link: https://leetcode.com/problems/string-to-integer-atoi/

// Implement atoi which converts a string to an integer.

// solution(use string stream)
int myAtoi(string str) {
       if(str.size()==0)
           return 0;
        if(str.back()==' ')
            str.push_back(0);
        stringstream s(str);
        int x;
        s >> x;
        return x;
    }