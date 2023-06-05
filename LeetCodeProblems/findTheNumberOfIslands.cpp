// TRIED DISJOINT SET APPROACH
//class Solution{
// public:
//     // Function to find the number of islands.
//     pair<int,int> find_parent(vector<vector<pair<int,int>>>& parents,int x,int y)
//     {
//         if(parents[x][y].first==x && parents[x][y].second==y) return {x,y};
//         else return parents[x][y]=find_parent(parents,parents[x][y].first,parents[x][y].second);
//     }
//     void union_set(vector<vector<pair<int,int>>>& parents,vector<vector<int>>& rank,int x1,int y1,int x2,int y2)
//     {
//         pair<int,int> p1=find_parent(parents,x1,y1);
//         pair<int,int> p2=find_parent(parents,x2,y2);
//         if(p1.first==p2.first && p1.second==p2.second) return;
//         if(rank[p1.first][p1.second]>rank[p2.first][p2.second]) swap(p1,p2);
//         parents[p1.first][p1.second]={p2.first,p2.second};
//         rank[p2.first][p2.second]+=rank[p1.first][p1.second];
//     }
//     bool isValid(vector<vector<char>>& grid,vector<vector<bool>>& vis,int x,int y)
//     {
//         if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && vis[x][y]==false && grid[x][y]=='1') return true;
//         return false;
//     }
//     void solve(vector<vector<char>>& grid,vector<vector<pair<int,int>>>& parents,vector<vector<int>>& rank,vector<vector<bool>>& vis,int crow=0,int ccol=0)
//     {
//         int drows[]={-1,+1,0,0,-1,+1,-1,+1};
//         int dcols[]={0,0,-1,+1,-1,+1,+1,-1};
//         vis[ccol][crow]=true;
//         for(int i=0;i<8;i++)
//         {
//             int nrow=crow+drows[i];
//             int ncol=ccol+dcols[i];
//             if(isValid(grid,vis,nrow,ncol))
//             {
//                 union_set(parents,rank,nrow,ncol,crow,ccol);
//                 solve(grid,parents,rank,vis,nrow,ncol);
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         // Code here
        
//         //Initiation
        
//         vector<vector<pair<int,int>>> parents;
//         vector<vector<int>> rank;
//         vector<vector<bool>> vis;
//         for(int i=0;i<grid.size();i++)
//         {
//             for(int j=0;j<grid[0].size();j++)
//             {
//                 parents[i][j]={i,j};
//                 rank[i][j]=1;
//                 vis[i][j]=false;
//             }
//         }
        
//         // Solution
        
//         solve(grid,parents,rank,vis);
        
//         // Finding Answer
        
//         int ans=0;
//         for(int i=0;i<grid.size();i++)
//         {
//             for(int j=0;j<grid[0].size();j++)
//             {
//                 if(grid[i][j]=='1' && parents[i][j].first==i && parents[i][j].second==j) ans++;
//             }
//         }
//         return ans;
//     }
// };

// DFS APPROACH

class Solution {
  public:
    // Function to find the number of islands.
    bool isSafe(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]=='1' && vis[i][j]==false) return true;
        else return false;
    }
    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& vis){
        int drows[]={-1,0,+1,0,-1,+1,-1,+1};
        int dcols[]={0,-1,0,+1,-1,+1,+1,-1};
        vis[i][j]=true;
        for(int k=0;k<8;k++)
        {
            int x=i+drows[k];
            int y=j+dcols[k];
            if(isSafe(grid,x,y,vis)){
                dfs(grid,x,y,vis);
            }
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int N=n*m;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='0') vis[i][j]=true;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]){
                    dfs(grid,i,j,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};