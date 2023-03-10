lass Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool helper(int src,vector<int> adj[],vector<bool>& visited,int parent)
    {
        visited[src]=true;
        for(auto i:adj[src])
        {
            if(i!=parent)
            {
                if(visited[i]) return true;
                else if(!visited[i] && helper(i,adj,visited,src)) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && helper(i,adj,visited,-1)){
                return true;
            }
        }
        return false;
    }
};