class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    int find_par(int x,vector<int>& parents)
    {
        if(parents[x]==x) return x;
        else return parents[x]=find_par(parents[x],parents);
    }
    void union_set(int x,int y,vector<int>& parents)
    {
        x = find_par(x,parents);
        y=find_par(y,parents);
        if(x!=y)
        {
            if(x>y) swap(x,y);
            parents[y]=x;
        }
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> parents(V,0);
	    for(int i=0;i<V;i++)
	    {
	        parents[i]=i;
	    }
	    unordered_set<int> vis;
	    for(int i=0;i<V;i++)
	    {
	        for(auto ele:adj[i])
	        {
	            if(vis.find(ele)==vis.end())
	            {
	               int x=find_par(i,parents);
	               int y=find_par(ele,parents);
	               if(x==y) return true;
	               union_set(x,y,parents);
	            }
	        }
	        vis.insert(i);
	    }
	    return false;
	}
};