class Solution{   
public:
//map {int->int} 
    int getPairsCount(int arr[], int n, int k) {
        // code here
        map<int,int> mp;
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
           if(mp.find(k-arr[i])!=mp.end())
           {
               cnt+=mp[k-arr[i]];
           }
           mp[arr[i]]++;
        }
        return cnt;
    }
};