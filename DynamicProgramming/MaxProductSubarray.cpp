// Link: https://leetcode.com/problems/maximum-product-subarray/

// solution:
    int maxProduct(vector<int>& arr) {
        int max_until=arr[0];
        int min_until=arr[0];
        int ans=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            int temp=max(arr[i],max(min_until*arr[i],max_until*arr[i]));
            min_until=min(arr[i],min(arr[i]*min_until,arr[i]*max_until));
            max_until=temp;
            ans=max(ans,max(max_until,min_until));
        }
        return ans;
    }

