class Solution {
public:
    void solve(vector<vector<string>>& ans,vector<string> board,int n,vector<bool> backwardSTRAIGHT, vector<bool> backwardDIAGONALUP, vector<bool> backwardDIAGONALDOWN,int currQueen=0)
    {
        if(currQueen==n){
            ans.push_back(board);
            return;
        }
        for(int currQueenPos=0;currQueenPos<n;currQueenPos++)
        {
            if(!backwardSTRAIGHT[currQueenPos] && !backwardDIAGONALUP[(n-1)+(currQueen-currQueenPos)] && !backwardDIAGONALDOWN[currQueenPos+currQueen])
            {
                board[currQueenPos][currQueen]='Q';
                backwardSTRAIGHT[currQueenPos]=true;
                backwardDIAGONALUP[(n-1)+(currQueen-currQueenPos)]=true;\
                backwardDIAGONALDOWN[currQueenPos+currQueen]=true;
                solve(ans,board,n,backwardSTRAIGHT,backwardDIAGONALUP,backwardDIAGONALDOWN,currQueen+1);
                backwardSTRAIGHT[currQueenPos]=false;
                backwardDIAGONALUP[(n-1)+(currQueen-currQueenPos)]=false;\
                backwardDIAGONALDOWN[currQueenPos+currQueen]=false;
                board[currQueenPos][currQueen]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> backwardSTRAIGHT(n,false);
        vector<bool> backwardDIAGONALUP(2*n-1,false);
        vector<bool> backwardDIAGONALDOWN(2*n-1,false);
        vector<string> board(n,string(n,'.'));

        solve(ans,board,n,backwardSTRAIGHT,backwardDIAGONALUP,backwardDIAGONALDOWN);
        return ans;
    }
};