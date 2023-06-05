class Solution {
public:
    bool isCyclic(vector<vector<int>>& graph,vector<bool>& stack,vector<bool>& vis,vector<int>& isSafe,int curr)
    {
        stack[curr]=true;
        vis[curr]=true;
        bool ans=false;
        for(auto ele:graph[curr]){
            if(stack[ele]==true && vis[ele]==true) return true;
            else if(stack[ele]==false && vis[ele]==false)
            {
                if (isCyclic(graph,stack,vis,isSafe,ele)) return true;
            }
        }
        stack[curr]=false;
        isSafe[curr]=true;
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int> ans;
        vector<bool> stack(N,false);
        vector<bool> vis(N,false);
        vector<int> isSafe(N,0);
        for(int i=0;i<N;i++)
        {
            if(!vis[i]) isCyclic(graph,stack,vis,isSafe,i);
        }
        for(int i=0;i<N;i++){
            if(isSafe[i]) ans.push_back(i);
        }
        return ans;
    }
};