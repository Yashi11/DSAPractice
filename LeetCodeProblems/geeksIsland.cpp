class Solution{   
public:
    void dfs(vector<vector<int>> &grid,int N,int M,vector<vector<bool>>& reachable,int x,int y)
    {
        int drows[]={-1,0,+1,0};
        int dcols[]={0,-1,0,+1};
        reachable[x][y]=true;
        for(int i=0;i<4;i++){
            int r=x+drows[i];
            int c=y+dcols[i];
            if(r>=0 && c>=0 && r<N && c<M && reachable[r][c]==false)
            {
                if(grid[r][c]>=grid[x][y]) dfs(grid,N,M,reachable,r,c);
            }
        }
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
        vector<vector<bool>> io(N,vector<bool>(M,false));
        vector<vector<bool>> as(N,vector<bool>(M,false));
        // indian ocean visited cells
        for(int i=0;i<M;i++){
            dfs(mat,N,M,io,0,i);
        }
        for(int i=0;i<N;i++){
            dfs(mat,N,M,io,i,0);
        }
        // arabian sea visited cells
        for(int i=0;i<M;i++){
            dfs(mat,N,M,as,N-1,i);
        }
        for(int i=0;i<N;i++){
            dfs(mat,N,M,as,i,M-1);
        }
        
        int ans=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(io[i][j]==true && as[i][j]==true){
                    ans++;
                }
            }
        }
        return ans;
    }
};