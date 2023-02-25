//NAIVE SOLN
// class Solution 
// {
//     public:
//     //Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& arr, int n) 
//     {
//         // code here
//         vector<int> colsSum;
//         vector<int> rowsSum;
//         for(int i=0;i<n;i++)
//         {
//             int currColSum=0;
//             for(int j=0;j<n;j++)
//             {
//                 currColSum+=arr[j][i];
//             }
//             colsSum.push_back(currColSum);
//         }
//         for(int i=0;i<n;i++)
//         {
//             int currRowSum=0;
//             for(int j=0;j<n;j++)
//             {
//                 currRowSum+=arr[i][j];
//             }
//             rowsSum.push_back(currRowSum);
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(colsSum[i]==n-1 && rowsSum[i]==0) return i;
//         }
//         return -1;
//     }
// };
//OPTIMAL SOLN
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        // code here
        int indx=-1;
        for(int i=0;i<n;i++)
        {
            int currColSum=0;
            for(int j=0;j<n;j++)
            {
                currColSum+=arr[j][i];
            }
            if(currColSum==n-1){ indx=i;break;}
        }
        if(indx==-1) return -1;
        int currRowSum=0;
            for(int j=0;j<n;j++)
            {
                currRowSum+=arr[indx][j];
            }
          
        if(currRowSum==0) return indx;
        return -1;
    }
};