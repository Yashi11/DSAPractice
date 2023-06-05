class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void findTopoSort(vector<vector<int>>& adj,stack<int>& st,vector<bool>& vis,int curr)
	{
	    vis[curr]=true;
	    for(auto ele:adj[curr])
	    {
	        if(!vis[ele]) findTopoSort(adj,st,vis,ele);
	    }
	    st.push(curr);
	}
	void dfs(vector<vector<int>>& adj,vector<bool>& vis,int curr){
	    vis[curr]=true;
	    for(auto ele:adj[curr])
	    {
	        if(!vis[ele]) dfs(adj,vis,ele);
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // STEP 1: Get nodes in stack (Topological Sort)
        vector<bool> vis1(V,false);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis1[i]) findTopoSort(adj,st,vis1,i);
        }
        vis1.clear();
        // STEP 2: Take Transpose of graph
        vector<vector<int>> adjT(V,vector<int>(0));
        for(int i=0;i<V;i++)
        {
            for(auto e:adj[i])
            {
                adjT[e].push_back(i);
            }
        }
       // STEP 3: Perform DFS as per transpose of graph and stack
        vector<bool> vis2(V,false);
        int ans=0;
        while(!st.empty())
        {
            int curr=st.top();
            st.pop();
           if(!vis2[curr]){
               dfs(adjT,vis2,curr);
               ans++;
           } 
        }
        return ans;
    }
};