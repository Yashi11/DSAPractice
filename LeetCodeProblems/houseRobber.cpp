class Solution {
public:
    map<int,int> dp;
    int rob(vector<int>& nums,int indx=0) {
        if(indx>=nums.size()) return 0;
        if(dp.find(indx)!=dp.end()) return dp[indx];
        else{
            //include this house
            int ans1=rob(nums,indx+2)+nums[indx];
            int ans2=rob(nums,indx+1);
            dp[indx]=max(ans1,ans2);
            return dp[indx];
        }
    }
};