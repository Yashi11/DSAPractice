// Naive O(N^2) Solution
//class Solution
// {
//     public:
//         int closestToZero(int arr[], int n)
//         {
//             int ans=INT_MAX;
//             bool isNeg=false;
//             for(int i=0;i<n-1;i++)
//             {
//                 for(int j=i+1;j<n;j++)
//                 {
//                   if(abs(arr[i]+arr[j])<ans)
//                   {
//                       if(arr[i]+arr[j]<0) isNeg=true;
//                       else isNeg=false;
//                       ans=abs(arr[i]+arr[j]);
//                   }
//                 }
//             }
//             if(isNeg) return -1*ans;
//             else return ans;
//         }
// };

//Optimal O(NlogN) Solution
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here 
            sort(arr,arr+n);
            int st=0;
            int en=n-1;
            int ans=INT_MAX;
            int flag=0;
            while(st<en)
            {
                if(abs(arr[st]+arr[en])<abs(ans))
                {
                    ans=arr[st]+arr[en];
                }
                else if(abs(arr[st]+arr[en])==abs(ans))
                {
                    ans=max(ans,arr[st]+arr[en]);
                }
                if(arr[st]+arr[en]<0) st++;
                else en--;
            }
            return ans;
        }
};