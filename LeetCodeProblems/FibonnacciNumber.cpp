class Solution {
public:
    int helper(int n,map<int,int>& mp)
    {
        if(mp.find(n) != mp.end())
        {
            return mp[n];
        }
        else{
            int ans=helper(n-1,mp)+helper(n-2,mp);
            mp[n]=ans;
            return ans;
        }
    }
    int fib(int n) {
        map<int,int> mp;
        mp[0]=0;
        mp[1]=1;
        return helper(n,mp);
    }
};