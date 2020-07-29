// Link: https://leetcode.com/problems/integer-to-roman/

// solution: 
    string intToRoman(int num) {
        vector<string> roman {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	    vector<int> no {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i=0;
        string ans="";
        while(num!=0)
        {
            if(num>=no[i])
            {
                num-=no[i];
                ans+=roman[i];
            }
            else
                i++;
        }
        return ans;
    }