class Solution {
public:
    vector<vector<int>> dfs(vector<vector<int>>& graph,int src,int dest)
    {
        if(src==dest)
        {
            vector<int> currAns;
            currAns.push_back(dest);
            return {currAns};
        }
        vector<vector<int>> ans;
        for(auto e:graph[src])
        {
           vector<vector<int>> rcvdAns=dfs(graph,e,dest);
                for(auto rcvd:rcvdAns){
                    rcvd.insert(rcvd.begin(),src);
                    ans.push_back(rcvd);
                }
        }
        return ans;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        // 0 is the source
        return dfs(graph,0,n-1);
    }
};