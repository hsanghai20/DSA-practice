// Link : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Returns Length of the required subarray 
int maxLen(int arr[], int n) 
{  
    unordered_map<int, int> presum; 
  
    int sum = 0; 
    int max_len = 0; 
    for (int i = 0; i < n; i++) { 
        sum += arr[i]; 
  
        if (arr[i] == 0 && max_len == 0) 
            max_len = 1; 
        if (sum == 0) 
            max_len = i + 1;  
        if (presum.find(sum) != presum.end()) { 
            max_len = max(max_len, i - presum[sum]); 
        } 
        else { 
            presum[sum] = i; 
        } 
    } 