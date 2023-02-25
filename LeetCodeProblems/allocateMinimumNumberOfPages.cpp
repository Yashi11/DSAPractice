// ADVANCED BINARY SEARCH APPROACH
class Solution 
{
    public:
    bool check(int A[],int N,int M,int pages)
    {
        int currPages=0;
        int expectedKids=1;
        for(int i=0;i<N;i++)
        {
            if(currPages+A[i]>pages)
            {
                currPages=0;
                expectedKids++;
            }
            currPages+=A[i];
        }
        if(expectedKids>M) return false;
        else return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        //code here
        int left=INT_MIN;
        int right=0;
        for(int i=0;i<N;i++)
        {
            left=max(left,A[i]);
            right+=A[i];
        }
        int mid;
        int ans=-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(check(A,N,M,mid))
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