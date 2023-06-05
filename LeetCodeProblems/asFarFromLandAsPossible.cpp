// BFS Approach Question similar to Rotten Oranges
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
       vector<vector<int>> vis(n,vector<int>(n,0));
       queue<pair<pair<int,int>,int>> q;
       int land=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(grid[i][j]==1)
               {
                   q.push({{i,j},0});
                   vis[i][j]=1;
               }
               else if(grid[i][j]==0)
               {
                   land++;
               }
           }
       }
       int ans=-1;
       int drow[]={-1,0,+1,0};
       int dcol[]={0,-1,0,+1};
       while(!q.empty())
       {
           int r=q.front().first.first;
           int c=q.front().first.second;
           int d=q.front().second;
           q.pop();
           ans=max(ans,d);
           for(int i=0;i<4;i++)
           {
               int currRow=r+drow[i];
               int currCol=c+dcol[i];
               if(currRow>=0 && currCol>=0 && currRow<n && currCol<n && grid[currRow][currCol]==0 && vis[currRow][currCol]==0)
               {
                   vis[currRow][currCol]=1;
                   q.push({{currRow,currCol},d+1});
               }
           }
       }
       if(land!=0) return ans;
       else return -1; 
    }
};