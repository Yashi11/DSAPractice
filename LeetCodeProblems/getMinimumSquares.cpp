class Solution{
	public:
	map<int,int> dp;
	Solution(){
	    dp[0]=0;
	    dp[1]=1;
	    dp[2]=2;
	    dp[3]=3;
	}
	int MinSquares(int n)
	{
	    // Code here
	    if(dp.find(n)!=dp.end()) return dp[n];
	    int ans=INT_MAX;
	    for(int i=1;i*i<=n;i++)
	    {
	        ans = min(MinSquares(n-(i*i))+1,ans);
	    }
	    return dp[n]=ans;
	    
	}
};