class Solution {
public:
    
    int solve(vector<int>& nums,vector<int>& dp,int ind=0)
    {
        if(ind==nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int currVal=nums[ind];
        int currSum=nums[ind];
        int index=ind+1;
        while(index<nums.size() && nums[index]==currVal)
        {
            currSum+=nums[index];
            index++;
        }
        while(index<nums.size() && nums[index]==currVal+1)
        {
            index++;
        }
        dp[ind]=max(currSum+solve(nums,dp,index),solve(nums,dp,ind+1));
        return dp[ind];
    }
    int deleteAndEarn(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<int> dp(nums.size(),-1);
        return solve(nums,dp,0);

    }
};