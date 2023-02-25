class Solution {
public:
    bool isSafe(vector<string> board,int x,int y,int n)
    {
        if(x<0 || y<0 || x>=n || y>=n)
        {
            return false;
        }
        int tempX=x;int tempY=y;
        //backwards STRAIGHT
        while(y>=0)
        {
            if(board[x][y]=='Q') return false;
            y--;
        }
        y = tempY;
        //backwards DIAGONALLY_UP
        while(x>=0 && y>=0)
        {
            if(board[x][y]=='Q') return false;
            y--;x--;
        }
        y=tempY;x=tempX;
        //backwards DIAGONALLY_DOWN
        while(x<n && y>=0)
        {
            if(board[x][y]=='Q') return false;
            y--;x++;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans,vector<string> board,int n,int currQueen=0)
    {
        if(currQueen==n){
            ans.push_back(board);
            return;
        }
        for(int currQueenPos=0;currQueenPos<n;currQueenPos++)
        {
            if(isSafe(board,currQueenPos,currQueen,n))
            {
                board[currQueenPos][currQueen]='Q';
                solve(ans,board,n,currQueen+1);
                board[currQueenPos][currQueen]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(ans,board,n);
        return ans;
    }
};