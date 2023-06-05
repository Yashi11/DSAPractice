// Naive Approach

// class Solution{   
// public:
//     int median(vector<vector<int>> &matrix, int R, int C){
//         // code here     
//         int n=R*C;
//         vector<int> nums;
//         for(int i=0;i<R;i++)
//         {
//             for(int j=0;j<C;j++)
//             {
//                 nums.push_back(matrix[i][j]);
//             }
//         }
//         sort(nums.begin(),nums.end());
//         if(n%2==1) return nums[n/2];
//         else return (nums[n/2]+nums[(n/2)-1])/2;
//     }
// };


// Advanced binary Search Approach
class Solution{   
public:
    int countSmallerThanMid(vector<int> row,int mid)
    {
        int l=0;
        int h=row.size()-1;
        int m;
        while(l<=h)
        {
            m=(l+h)/2;
            if(row[m]<=mid) l=m+1;
            else h=m-1;
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here 
        int low=1;
        int high=1e9;
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            int cnt=0;
            for(int i=0;i<R;i++)
            {
                cnt+= countSmallerThanMid(matrix[i],mid);
            }
            if(cnt<= (R*C)/2) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};