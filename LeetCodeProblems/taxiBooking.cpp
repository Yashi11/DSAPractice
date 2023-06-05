class Solution{
public:
    int minimumTime(int N,int curr,vector<int> &pos,vector<int> &time){
        int ans=INT_MAX;
        for(int i=0;i<N;i++)
        {
            int dist=curr-pos[i];
            ans = min(ans,abs(dist)*time[i]);
        }
        return ans;
    }
};