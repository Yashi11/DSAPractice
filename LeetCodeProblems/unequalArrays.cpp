class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        int sumA=0;
        int sumB=0;
        vector<int> evenOddA[2]; //0->even & 1->odd
        vector<int> evenOddB[2];
        
        for(int i=0;i<N;i++)
        {
            sumA+=A[i];
            sumB+=B[i];
            if(A[i]%2==0) evenOddA[0].push_back(A[i]);
            else evenOddA[1].push_back(A[i]);
            if(B[i]%2==0) evenOddB[0].push_back(B[i]);
            else evenOddB[1].push_back(B[i]);
        }
        if(sumA!=sumB || evenOddA[0].size()!=evenOddB[0].size()) return -1;
        long long int ans=0;
        for(int i=0;i<2;i++)
        {
            sort(evenOddA[i].begin(),evenOddA[i].end());
            sort(evenOddB[i].begin(),evenOddB[i].end());
            for(int j=0;j<evenOddA[i].size();j++)
            {
                ans+=abs(evenOddA[i][j]-evenOddB[i][j])/2;
            }
        }
        return ans/2;
    }
};