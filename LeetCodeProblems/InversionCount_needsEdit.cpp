class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long int l,long long int m, long long int h){
        vector<int> temp;
        long long int left=l;
        long long int right=m+1;
        long long count=0;
        while(left<=m && right<=h)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                count = count + (m-left+1);
                right++;
            }
        }
        while(left<=m)
        {
            temp.push_back(arr[left]);
                left++;
        }
        while(right<=h)
        {
            temp.push_back(arr[right]);
                right++;
        }
        for(int i=l;i<=h;i++)
        {
            arr[i]=temp[i-l];
        }
        return count;
    }
    long long int mergeSort(long long arr[],long long low,long long high)
    {
        if(low>=high) return 0;
        long long mid=(low+high)/2;
        long long invC=0;
        invC += mergeSort(arr,low,mid);
        invC += mergeSort(arr,mid+1,high);
        invC += merge(arr,low,mid,high);
        return invC;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr,0,N-1);
    }

};