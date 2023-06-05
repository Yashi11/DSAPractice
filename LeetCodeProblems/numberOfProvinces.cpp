class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>& vis,int s)
    {
        vis[s]=true;
        int n=isConnected.size();
        for(int i=0;i<n;i++)
        {
            if(isConnected[s][i]==1)
            {
                if(vis[i]==false)
                {
                    dfs(isConnected,vis,i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //disjoint set union
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                ans++;
                dfs(isConnected,vis,i);
            }
        }
        return ans;
    }
};