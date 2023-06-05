class Solution {
public:
// O(N^2)
    bool check(vector<int> piles, int x, int h){
        long long int eh=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%x==0) {
                eh=eh+(piles[i]/x);
            }
            else{
                eh=eh+(piles[i]/x)+1;
            }
        }
        return eh<=h?true:false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=0;
        for(int i=0;i<piles.size();i++)
        {
            high=max(high,piles[i]);
        }
        long long int low=1;
        long long int mid;
        long long int ans=high;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(check(piles,mid,h)){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return (int)ans;
    }
};