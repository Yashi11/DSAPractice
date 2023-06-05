class Solution {
public:
   bool dfs(vector<int> adj[],vector<bool>& vis,vector<bool>& stack,int curr)
   {
       vis[curr]=true;
       stack[curr]=true;
       for(auto ele:adj[curr])
       {
           if(stack[ele]) return true;
           if(!vis[ele]){
               if(dfs(adj,vis,stack,ele)) return true;
           }
       }
       stack[curr]=false;
       return false;
   }
	bool isPossible(int N, vector<pair<int, int> >& pq) {
	    // Code here
	    vector<int> adj[N];
	    for(auto p:pq){
	        adj[p.first].push_back(p.second);
	    }
	    vector<bool> vis(N,false);
	    vector<bool> stack(N,false);
	    bool ans;
	    for(int i=0;i<N;i++)
	    {
	        if(!vis[i]) ans= dfs(adj,vis,stack,i);
	        if(ans==true) return false;
	    }
	    return true;
	}
};