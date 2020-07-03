// Link: https://leetcode.com/problems/xor-queries-of-a-subarray/

// Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], 
//for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
//Return an array containing the result for the given queries.

// solution
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int xoruntil[arr.size()];
        xoruntil[0]=0;
        vector <int> ans;
        for (int i=1;i<arr.size();i++)
            xoruntil[i]=xoruntil[i-1]^arr[i-1];
        for (int i=0;i<queries.size();i++)
          ans.push_back(xoruntil[queries[i][1]]^arr[queries[i][1]]^xoruntil[queries[i][0]]);
        return ans;
    }