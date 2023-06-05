class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size();
        int m=matrix[0].size();
        
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int currScore=0;
                if(matrix[i][j]==1)
                {
                    int r=i;
                    int c=j;
                    //up
                    if(i-1>=0 && matrix[i-1][j]==0) currScore+=1;
                    //left
                    if(j-1>=0 && matrix[i][j-1]==0) currScore+=1;
                    //down
                    if(i+1<n && matrix[i+1][j]==0) currScore+=1;
                    //right
                    if(j+1<m && matrix[i][j+1]==0) currScore+=1;
                    //diagonally left up
                    if(i-1>=0 && j-1>=0 && matrix[i-1][j-1]==0) currScore+=1;
                    //diagonally right down
                    if(i+1<n && j+1<m && matrix[i+1][j+1]==0) currScore+=1;
                    //diagonally right up
                    if(i-1>=0 && j+1<m && matrix[i-1][j+1]==0) currScore+=1;
                    //diagonally down left
                    if(i+1<n && j-1>=0 && matrix[i+1][j-1]==0) currScore+=1;
                    if(currScore>0 && currScore%2==0){ans++;}
                }
                else{
                    continue;
                }
            }
        }
        return ans;
    }
};