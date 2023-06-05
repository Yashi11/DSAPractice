class Solution
{
    public:
    //Function to merge two nodes a and b.
    int find_parent(int a,int par[])
    {
        if(a==par[a]) return a;
        else return par[a]=find_parent(par[a],par);
    }
    void union_( int a, int b, int par[], int rank1[]) 
    {
        //code here
        int x = find_parent(a,par);
        int y = find_parent(b,par);
        if(x!=y)
        {
            if(rank1[x]<rank1[y]) swap(x,y);
            par[y]=x;
            rank1[x]+=rank1[y];
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        //code here
        return find_parent(x,par)==find_parent(y,par);
    }
};