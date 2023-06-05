// Naive Approach

// class Solution
// {
//     public:
//     //Function to find the minimum element in sorted and rotated array.
//     int minNumber(int arr[], int low, int high)
//     {
//         // Your code here
//       for(int i=low;i<=high;i++)
//       {
//           if(i!=low && i!=high && arr[i]>arr[i-1] && arr[i]>arr[i+1]) return arr[i+1];
//           else if(i!=low && i!=high && arr[i]<arr[i-1] && arr[i]<arr[i+1]) return arr[i];
//           if(i==high && arr[i]<arr[i-1]) return arr[high];
//       }
//       return arr[low];
        
//     }
// };

// Optimized Approach
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(mid<high && arr[mid+1]<arr[mid]) return arr[mid+1];
            else if(mid>low && arr[mid]<arr[mid-1]) return arr[mid];
            if(arr[mid]>arr[high]){
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        if(low==high) return arr[high];
        return arr[0];
        
    }
};