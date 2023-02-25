class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      vector<int> scores(N,0);
      for(int i=0;i<Edge.size();i++){
          if(Edge[i]!=-1) scores[Edge[i]]+=i;
      }
      
      int mxCell=0;
      for(int i=1;i<N;i++)
      {
          if(scores[i]>=scores[mxCell]) mxCell=i;
      }
      return mxCell;
  }
};