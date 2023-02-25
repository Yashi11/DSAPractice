// ADVANCED BINARY SEARCH, here instead of having a boolean check we have an integer check***
class Solution{
    public:
    int check(int tree[],int n,int k,int mid)
    {
        int expectedWood=0;
        for(int i=0;i<n;i++)
        {
            if(tree[i]>mid)
            {
                expectedWood+=tree[i]-mid;
            }
        }
        if(expectedWood==k) return 0;
        else if(expectedWood<k) return +1;
        else return -1;
        
    }
    int find_height(int tree[], int n, int k)
    {
        // code here
        int left=0;
        int right=INT_MIN;
        for(int i=0;i<n;i++) right=max(right,tree[i]);
        int mid;
        int ans=-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            int temp=check(tree,n,k,mid);
            if(temp==0)
            {
                return mid;
            }
            else if(temp==1)
            {
                right=mid-1;
            }
            else if(temp==-1){
                left=mid+1;
            }
        }
        return ans;
    }
};