class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        int low=0;
        int high=v.size()-1;
        int mid;
        int firstOccur=0;
        int lastOccur=0;
        while(low<=high)
        {
           mid=(low+high)/2;
           if(v[mid]==x)
           {
               firstOccur=mid;
               lastOccur=mid;
               while(firstOccur>0 && v[firstOccur-1]==v[mid]) firstOccur--;
               while(lastOccur<v.size()-1 && v[lastOccur+1]==v[mid]) lastOccur++;
               return {firstOccur,lastOccur};
           }
           else if(v[mid]<x) low=mid+1;
           else high=mid-1;
        }
        return {-1,-1};
    }
};