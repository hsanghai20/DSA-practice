// Link: https://leetcode.com/problems/excel-sheet-column-number/
// Given a column title as appear in an Excel sheet, return its corresponding column number.

/*  A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
*/

// solution
int titleToNumber(string s) {
        int i=0;
        long long int ans=0;
        long long mul=1;
        while(i<s.length())
        {
            ans+=(s[s.length()-1-i]-'A'+1)*mul;
            i++;
            mul*=26;
        }
        return ans;
    }