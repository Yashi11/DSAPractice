class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxAfter;
        int maxEle=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--){
            maxEle = max(maxEle,prices[i]);
            if(maxEle>prices[i]) maxAfter.push_back(maxEle-prices[i]);
            else maxAfter.push_back(0);
        }
        int ans=INT_MIN;
        for(auto i:maxAfter){
            ans=max(ans,i);
        }
        return ans;
    }
};