class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int N=mat.size();
        int centre=mat[(int)N/2][(int)N/2];
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=mat[i][i];
            sum+=mat[i][N-i-1];
        }
        if(N%2==1) sum-=centre;
        return sum;
    }
};