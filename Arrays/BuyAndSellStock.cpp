// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//If you were only permitted to complete at most one transaction 
//(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// function
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mi=INT_MAX;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            mi=min(mi,prices[i]);
            ans=max(prices[i]-mi,ans);
        }
        return ans;
    }