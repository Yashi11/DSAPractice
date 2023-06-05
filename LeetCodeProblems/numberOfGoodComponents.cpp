// Find Components in a graph using DFS + modification is to check if indegree of each
	// member is equal to the members in the component-1
class Solution {
  public:
    void dfs(int i,vector<vector<int>>& adj,vector<bool>& vis,vector<int>& members)
    {
        vis[i]=true;
        members.push_back(i);
        for(auto j:adj[i])
        {
           if(!vis[j]) dfs(j,adj,vis,members);
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool> vis(V+1,false);
        int ans=0;
        for(int i=1;i<=V;i++)
        {
            if(!vis[i]){
                vector<int> members;
                dfs(i,adj,vis,members);
                bool flag=true;
                for(auto ele:members)
                {
                    if(adj[ele].size() < members.size()-1){
                        flag=false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};