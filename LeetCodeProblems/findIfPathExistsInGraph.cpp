class Solution {
public:
    int findParent(int a,vector<int>& parent)
    {
        if(parent[a]==a) return a;
        return parent[a]=findParent(parent[a],parent);
    }
    void union_set(int a,int b,vector<int>& parent,vector<int>& rank)
    {
        int x=findParent(a,parent);
        int y=findParent(b,parent);
        if(x!=y)
        {
            if(rank[x]<rank[y]) swap(x,y);
            parent[y]=x;
            rank[x]+=rank[y];
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<int> rank(n,1);
       for(auto e:edges)
       {
           union_set(e[0],e[1],parent,rank);
       }
       for(int i=0;i<n;i++)
       {
           parent[i]=findParent(i,parent);
       }
       return (parent[source]==parent[destination]);
    }
};