class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
    //Your code goes here
        vector<int> ans;
        sort(arr2,arr2+n);
        int st1=0;
        int st2=0;
        
        for(int i=0;i<m;i++)
        {
            int temp=upper_bound(arr2,arr2+n,arr1[i])-arr2;
            ans.push_back(temp);
        }
        return ans;
    }
};