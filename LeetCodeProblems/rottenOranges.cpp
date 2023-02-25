// BFS: Intuition here is that we are rotting all the neighbouring orages simultaneously
	// so we are choosing a breadth first traversal instead of DFS
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int nFresh=0;
        queue<pair<pair<int,int>,int>> q; //{{row,col},time}
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
              if(grid[i][j]==2)
              {
                  q.push({{i,j},0});
                  vis[i][j]=2;
              }
              else if(grid[i][j]==1) nFresh++;
          }
        }
        int ans=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,-1,0,+1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=max(ans,t);
            for(int i=0;i<4;i++)
            {
                int currRow=r+drow[i];
                int currCol=c+dcol[i];
                if(currRow>=0 && currCol>=0 && currRow<n && currCol<m && vis[currRow][currCol]==0 && grid[currRow][currCol]==1)
                {
                    vis[currRow][currCol]=2;
                    q.push({{currRow,currCol},t+1});
                    nFresh--;
                }
            }
            
        }
        if(nFresh==0) return ans;
        else return -1;
    }
};