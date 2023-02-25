// NAIVE SOLUTION O(N^2)


// class Solution {
//     public:
//         // Function to return the length of the
//         //longest subarray with ppositive product
//         int maxLength(vector<int> &arr,int n){
//           //code here
//           int len=0;
//           for(int i=0;i<n;i++)
//           {
//               int currProduct=arr[i];
//               for(int j=i+1;j<n;j++)
//               {
//                   if(arr[i]>0) arr[i]=1;
//                   else if(arr[i]<0) arr[i]=-1;
//                   currProduct*=arr[j];
//                   if(currProduct>0){
//                       len=max(len,j-i+1); 
//                   }
//               }
               
//           }
//           return len;
//         }
// };

// OPTIMAL SOLUTION
class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int firstNeg=-1;
           int countNeg=0;
           int len=0;
           int strt=0;
           for(int i=0;i<n;i++)
           {
             if(arr[i]==0)
             {
                 strt=i+1;
                 firstNeg=-1;
                 countNeg=0;
             }
             else if(arr[i]<0)
             {
                 countNeg++;
                 if(firstNeg==-1) firstNeg=i;
             }
             if(countNeg%2==0){
                     len=max(len,i-strt+1);
                 }
             else{
                     len=max(len,i-firstNeg);
                 }
             }
             return len;
           }
};