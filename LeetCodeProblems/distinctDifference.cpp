class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        vector<int> left(N,0);
        unordered_set<int> us;
        for(int i=0;i<N;i++)
        {
            left[i]=us.size();
            us.insert(A[i]);
        }
        us.clear();
        for(int i=N-1;i>=0;i--)
        {
            left[i]-=us.size();
            us.insert(A[i]);
        }
        return left;
    }
};