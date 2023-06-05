class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int l=0;
        int h=a.size()-1;
        int m;
        int ans=0;
        while(l<=h)
        {
            m = (l+h)/2;
            ans=max(ans,a[m]);
            if(m-1>=0 && a[m]<a[m-1]) h=m-1;
            else if(m+1<a.size() && a[m]<a[m+1]) l=m+1;
            else return ans;
        }
        
        return ans;
    }
};
