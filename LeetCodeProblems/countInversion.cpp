class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long temp[],long long int st,long long int m,long long int en)
    {
       long long int k=st;
       long long int i=st;long long int j=m+1;
       long long int ans=0;
       while(i<=m && j<=en)
       {
           if(arr[i]<=arr[j]){
               temp[k++]=arr[i++];
           }
           else{
               temp[k++]=arr[j++];
               ans= ans+(m-i);
           }
       }
       while(i<=m){
           temp[k++]=arr[i++];
       }
       while(j<=en){
           temp[k++]=arr[j++];
       }
       for(int i=st;i<=en;i++)
       {
           arr[i]=temp[i];
       }
       return ans;
    }
    long long int mergeSort(long long arr[],long long temp[],long long int st,long long int en)
    {
        long long int ans=0;
        if(st>=en) return 0;
        int m=(st+en)/2;
        ans+=mergeSort(arr,temp,st,m);
        ans+=mergeSort(arr,temp,m+1,en);
        ans+= merge(arr,temp,st,m,en);
        return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return mergeSort(arr,temp,0,N-1);
    }
};