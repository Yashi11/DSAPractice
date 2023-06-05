class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        
        int sr=-1;
        int sc=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                    break;
                }
            }
        }
        // let me try bfs lol
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        q.push({sr,sc});
        vis[sr][sc]=true;
        int drows[]={-1,0,+1,0};
        int dcols[]={0,-1,0,+1};
        
        while(!q.empty())
        {
          int cr=q.front().first;
          int cc=q.front().second;
          q.pop();
          
          for(int i=0;i<4;i++)
          {
              int nr=cr+drows[i];
              int nc=cc+dcols[i];
              if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]!=0 && vis[nr][nc]==false){
                  if(grid[nr][nc]==2) return 1;
                  vis[nr][nc]=true;
                  q.push({nr,nc});
              }
          }
        }
        return 0;
         
    }
};