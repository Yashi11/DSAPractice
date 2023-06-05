// class Solution {
// public:
//     void help(int n, vector<vector<int>>& connections,int &ans,int ind,vector<bool>& vis)
//     {
//         vis[ind]=true;
//         for(int i=0;i<n-1;i++)
//         {
//             if(connections[i][0]==ind && vis[connections[i][1]]==false){
//                 ans++;
//                 help(n,connections,ans,connections[i][1],vis);
//             }
//             else if(connections[i][1]==ind && vis[connections[i][0]]==false)
//             {
//                 help(n,connections,ans,connections[i][0],vis);
//             }
//         }
//     }
//     int minReorder(int n, vector<vector<int>>& connections) {
//         int ans=0;
//         vector<bool>vis(n,false);
//         help(n,connections,ans,0,vis);
//         return ans;
//     }
// };

class Solution {
public:
    void help(int n, vector<vector<int>>& adj,int &ans,int ind,vector<bool>& vis)
    {
        vis[ind]=true;
        for(auto e:adj[ind])
        {
           if(e>0)
           {
               if(vis[e]==false)
               {
                   ans++;
                   help(n,adj,ans,e,vis);
               }
           }
           else{
               if(vis[-e]==false)
               {
                   help(n,adj,ans,-e,vis);
               }
           }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans=0;
        vector<vector<int>> adj(n);
        for (auto &c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        vector<bool> vis(n,false);
        help(n,adj,ans,0,vis);
        return ans;
    }
};