class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,100000000);
        dist[S]=0;
        bool flag=false;
        for(int i=0;i<V-1;i++)
        {
            for(auto e:edges)
            {
                int u=e[0];
                int v=e[1];
                int w=e[2];
                dist[v]=min(dist[v],w+dist[u]);
            }
        }
        for(auto e:edges)
        {
                int u=e[0];
                int v=e[1];
                int w=e[2];
                if(dist[v]>w+dist[u]){
                    return {-1};
                };
        }
        return dist;
    }
};