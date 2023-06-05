class Solution {
  public:
    long long solve(vector<int> A,int N,int M)
    {
        unordered_map<int,int> map;
        int cur=0;
        long long tot=0;
        long long ans=0;
        map[cur]=1;
        for(int i=0;i<N;i++){
            int x;
            if(A[i]>=M) x=1;
            else x=-1;
            if(x==-1) tot-=map[cur-1];
            else tot+=map[cur];
            cur+=x;
            ans+=tot;
            map[cur]=map[cur]+1;
        }
        return ans;
    }
    long long countSubarray(int N,vector<int> A,int M) {
        code here
        long long x=solve(A,N,M);
        long long y=solve(A,N,M+1);
        return x-y;
        
    }
};