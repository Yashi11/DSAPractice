//NAIVE SOLUTION O(2^N)

// https://www.youtube.com/watch?v=tSLiZAQG9NM

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int minO=arr[0];
        int maxO=arr[n-1];
        int ans=maxO-minO;
        for(int i=0;i<n;i++)
        {
            minO=min(arr[0]+k,arr[i]-k);
            maxO=max(arr[n-1]-k,arr[i-1]+k);
            ans=min(ans,maxO-minO);
        }
        return ans;
    }
};