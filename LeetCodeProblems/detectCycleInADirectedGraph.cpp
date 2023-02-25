// DSU Approach
// class Solution {
//   public:
//     // Function to detect cycle in an undirected graph.
    
//     int find_set(int v,vector<int>& parent)
//     {
//         if(parent[v]==v) return v;
//         else return parent[v]=find_set(parent[v],parent);
//     }
//     void union1(int x,int y,vector<int>& parent,vector<int>& size)
//     {
//         if(x!=y)
//         {
//             if(size[x]<size[y]) swap(x,y);
//             parent[y]=x;
//             size[x]+=size[y];
//         }
//     }
//     bool isCycle(int V, vector<int> adj[]) {
//         // Code here
//         vector<vector<int>> edges;
//         vector<int> parent(V,-1);
//         vector<int> size(V,1);
//         for(int i=0;i<V;i++)
//         {
//             for(auto j:adj[i])
//             {
//                 if(j>i){
//                     edges.push_back({i,j});
//                     parent[i]=i;
//                     parent[j]=j;
//                 }
//             }
//         }
//         for(auto e: edges)
//         {
//             int x=find_set(e[0],parent);
//             int y=find_set(e[1],parent);
//             if(x==y) return true;
//             union1(x,y,parent,size);
//         }
//         return false;
//     }
// };

//Optimal Approach
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(int src,vector<int> adj[],vector<bool>& vis,vector<bool>& inStack){
        inStack[src]=true;
        vis[src]=true;
        for(auto i:adj[src])
        {
            if(!vis[i] && helper(i,adj,vis,inStack)) return true;
            else if(inStack[i]) return true;
        }
        inStack[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<bool> inStack(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && helper(i,adj,vis,inStack)) return true;
        }
        return false;
    }
};