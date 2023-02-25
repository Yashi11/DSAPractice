class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    int countmyMFS(vector<int> adj[],int indx,vector<bool>& visited)
    {
        int count=0;
        visited[indx]=true;
        for(auto j:adj[indx])
        {
           if(!visited[j]) count=count+countmyMFS(adj,j,visited)+1;
        }
        return count;
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    
	    for(int i=0;i<V;i++)
	    {
	        vector<bool> visited(V,false);
	        if(countmyMFS(adj,i,visited)==V-1) return i;
	    }
	    return -1;
	}

};