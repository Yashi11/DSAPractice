class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frog[]) {
        // Code here
        vector<bool> leafTrk(leaves,false);
        for(int i=0;i<N;i++)
        {
            if(leafTrk[frog[i]-1]==false) //this statement was necessary for overcoming TLE
            {for(int j=frog[i];j<=leaves;j+=frog[i])
            {
                leafTrk[j-1]=true;
            }}
        }
        int ans=0;
        for(auto i:leafTrk)
        {
            if(i==false) ans++;
        }
        return ans;
    }
};
