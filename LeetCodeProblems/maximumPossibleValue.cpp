class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        int minLen=INT_MAX;
        long long int tot_stick=0;
        long long int tot_per=0;
        for(int i=0;i<N;i++)
        {
            if(B[i]%2==1) B[i]--;
            if(B[i]>=2) minLen=min(minLen,A[i]);
            tot_stick +=B[i];
            tot_per += B[i]*A[i];
        }
        if(tot_stick%4!=0) tot_per-=2*minLen;
        return tot_per;
    }
};