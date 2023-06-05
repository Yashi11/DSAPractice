class Solution {
public:
    void dfs(vector<vector<int>>& grid,int r,int c)
    {
        int n=grid.size();
        int m=grid[0].size();

        grid[r][c]=1;
        int drows[4]={0,-1,0,1};
        int dcols[4]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int nr=r+drows[i];
            int nc=c+dcols[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==0){
                dfs(grid,nr,nc);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i*j==0 || i==n-1 || j==m-1) && (grid[i][j]==0))
                    dfs(grid,i,j);
            }
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};