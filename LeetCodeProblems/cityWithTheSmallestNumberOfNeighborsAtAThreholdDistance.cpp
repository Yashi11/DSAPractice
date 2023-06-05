class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     vector<vector<int>> matr(n,vector<int>(n,INT_MAX));
                     for(auto edge: edges)
                     {
                         int from=edge[0];
                         int to=edge[1];
                         int wt=edge[2];
                         matr[from][to]=wt;
                         matr[to][from]=wt;
                     }
                     for(int i=0;i<n;i++) matr[i][i]=0;
                     for(int k=0;k<n;k++)
                     {
                         for(int i=0;i<n;i++)
                         {
                             for(int j=0;j<n;j++)
                             {
                                 if(matr[i][k]!=INT_MAX && matr[k][j]!=INT_MAX)
                                    matr[i][j]=min(matr[i][j],matr[i][k]+matr[k][j]);
                             }
                         }
                     }
                    //  for(int i=0;i<n;i++)
                    //  {
                    //      for(int j=0;j<n;j++)
                    //      {
                    //          cout<<matr[i][j]<<" ";
                    //      }
                    //      cout<<"\n";
                    //  }
                     int ans=0;
                     for(int i=0;i<n;i++)
                     {
                         int cCity=0;
                         for(int j=0;j<n;j++)
                         {
                             if(matr[i][j]<=distanceThreshold) cCity++;
                         }
                         matr[i][0]=cCity;
                         if(matr[i][0]<=matr[ans][0]) ans=i;
                     }
                     return ans;
                 }
};