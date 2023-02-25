class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxProfit=0;
        int mx=prices[prices.size()-1];
        for(int i=prices.size()-1;i>=0;i--)
        {
            mxProfit= max(mxProfit,mx-prices[i]);
            mx=max(mx,prices[i]);
        }
        return mxProfit;   
    }
};