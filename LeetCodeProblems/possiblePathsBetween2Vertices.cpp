class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int dfs(vector<int> adj[],int src,int dest){
        if(src==dest) return 1;
        int ans=0;
        for(auto ele:adj[src]){
                ans+=dfs(adj,ele,dest);
        }
        return ans;
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        int ans=0;
        return dfs(adj,source,destination); 
    }
};