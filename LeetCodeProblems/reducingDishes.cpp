class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<int> sumBefore(n,0);
        sumBefore[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            sumBefore[i]=sumBefore[i+1]+satisfaction[i+1];
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=satisfaction[i]*(i+1);
        }
        for(int i=0;i<n;i++)
        {
            int currSum=sum-satisfaction[i]-sumBefore[i];
            if(currSum<=sum) return sum;
            else sum=currSum;
        }
        return sum;
    }
};