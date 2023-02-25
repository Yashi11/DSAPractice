class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    for(int k=0;k<matrix.size();k++)
	    {
	        for(int i=0;i<matrix.size();i++)
	        {
	            for(int j=0;j<matrix.size();j++)
	            {
	                if(matrix[i][k]==-1 || matrix[k][j]==-1) continue;
	                // BELOW LINE IS IMPORTANT EXTREAMUM
	                if(matrix[i][j]!=-1) matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	                else matrix[i][j]=matrix[i][k]+matrix[k][j];
	            }
	        }
	    }
	}
};