class Solution{
public:
    int binarySearch(vector<int>& temp,int k)
    {
        int l=0;
        int h=temp.size()-1;
        int m;
        while(l<=h)
        {
            m=(l+h)/2;
            if(temp[m]==k)
            {
                while(m>0 && temp[m-1]==k) m--;
                return m;
            }
            else if(temp[m]<k)
            {
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return l;
    }
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        vector<int> temp;
        for(int i=0;i<n/2;i++)
        {
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        int ans=0;
        for(int i=n/2;i<n;i++)
        {
            int target=arr[i]*5;
            int res=binarySearch(temp,target);
            if(res<n/2) ans=ans+(n/2-res);
        }
        return ans;
    }  
};