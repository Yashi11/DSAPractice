class Solution
{
  public:
  //main problem faced with keeping variables in long long or int data format
    bool check(int arr[],int n,int k,long long tm)
    {
        long long currTime=0;
        long long expectedPainters=1;
        for(int i=0;i<n;i++)
        {
            if(currTime+arr[i]>tm)
            {
                currTime=0;
                expectedPainters++;
                if(expectedPainters > k || arr[i]>tm) return false;
            }
            currTime+=(long long) arr[i];
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long left=0;
        long long right=0;
        for(int i=0;i<n;i++)
        {
            right+=arr[i];
        }
        long long mid;
        long long  ans=-1;
        while(left<=right){
            mid=(left+right)/2;
            if(check(arr,n,k,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};