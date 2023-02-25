class Solution{
public:
    vector<int> denoms={2000,500,200,100,50,20,10,5,2,1};
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        for(int i=0;i<denoms.size();i++)
        {
            if(denoms[i]<=N){
                while(N>=denoms[i])
                {
                    ans.push_back(denoms[i]);
                    N=N-denoms[i];
                }
            }
        }
        return ans;
        
    }
};