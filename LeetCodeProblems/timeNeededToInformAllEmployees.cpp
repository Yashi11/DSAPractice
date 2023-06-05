class Solution {
public:
    // int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    //     if(informTime[headID]==0) return 0;
    //     int ans=informTime[headID];
    //     int temp=0;
    //     for(int i=0;i<manager.size();i++){
    //         if(manager[i]==headID) temp=max(temp,numOfMinutes(n,i,manager,informTime));
    //     }
    //     return ans+temp;
    // }
    int dfs(int headID,vector<int>& informTime,unordered_map<int,vector<int>>& adj)
    {
        if(adj.find(headID)==adj.end()) return informTime[headID];
        int ans=0;
        for(int g:adj[headID])
        {
            ans=max(ans,dfs(g,informTime,adj));
        }
        return ans+informTime[headID];
    }
     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
         unordered_map<int,vector<int>> adjList;
         for(int i=0;i<n;i++)
         {
             if(manager[i]!=-1) adjList[manager[i]].push_back(i);
         }
         return dfs(headID,informTime,adjList);
     }
};