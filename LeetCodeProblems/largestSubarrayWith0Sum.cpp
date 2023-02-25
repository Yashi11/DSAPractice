class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int,int> mp;
        int currSum=0;
        mp[0]=-1;
        int len=0;
        for(int i=0;i<n;i++)
        {
           currSum=currSum+A[i];
           if(mp.find(currSum)==mp.end())
           {
               mp[currSum]=i;
           }
           else{
              len=max(len,i-mp[currSum]); 
           }
        }
        return len;
    }
};