class Solution
{
    public:
        int solve(int n)
        {
            int ans=0;
            while(n)
            {
                ans+=n/5;
                n=n/5;
            }
            return ans;
        }
        int findNum(int n)
        {
        //complete the function here
        int low=1;
        int high=5*n;
        int mid;
        int ans;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(solve(mid)>=n){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        }
};