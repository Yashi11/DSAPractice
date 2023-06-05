class Solution{
    public:
        
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
                vector<vector<int>> dp(N+2,vector<int>(N+2));
                vector<int> v;
                v.push_back(1);
                for(int i=0;i<N;i++)
                {
                    v.push_back(a[i]);
                }
                v.push_back(1);
                for(int i=N;i>0;i--)
                {
                    for(int j=i;j<=N;j++)
                    {
                        int cost=0;
                        for(int k=i;k<=j;k++)
                        {
                            int currCost = v[i-1]*v[k]*v[j+1]+dp[i][k-1]+dp[k+1][j];
                            cost=max(currCost,cost);
                        }
                        dp[i][j]=cost;
                    }
                }
                return dp[1][N];
        }
};