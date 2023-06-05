class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int> st;
        vector<int> ans(n,0);
      
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans[i]=prices[i];
                st.push(prices[i]);
                continue;
            }
            if(st.top()<=prices[i]){
                ans[i]=prices[i]-st.top();
                st.push(prices[i]);
            }
            else{
                st.pop();
                i++;
            }
        }
        return ans;
    }
};