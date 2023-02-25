class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int jumps=1;
        int maxR=arr[0];
        int steps=arr[0];
        if(n==1) return 0;
        else if(arr[0]==0) return -1;
        else{
            for(int i=1;i<n;i++)
            {
                if(i==n-1) return jumps;
                maxR=max(maxR,arr[i]+i);
                steps--;
                if(steps==0)
                {
                    jumps++;
                    if(i>=maxR) return -1;
                    steps=maxR-i;
                }
            }
        }
        return -1;
    }
};
