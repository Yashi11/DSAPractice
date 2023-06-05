class Solution {
public:
    int findParent(int a,vector<int>&parent)
    {
        if(parent[a]==a) return a;
        else return parent[a]=findParent(parent[a],parent);
    }
    bool help(int a,int b,vector<int>& parent,vector<int>& rank)
    {
        int x=findParent(a,parent);
        int y=findParent(b,parent);
        if(x==y) return true;
        else{
            if(rank[x]<rank[y]) swap(x,y);
            parent[y]=x;
            rank[x]+=rank[y];
            return false;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto e:edges)
        {
            if(help(e[0]-1,e[1]-1,parent,rank)) return e;
            else continue;
        }
        return {};
    }
};