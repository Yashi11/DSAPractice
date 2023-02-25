class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size(),"");
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push(make_pair(score[i],i));
        }
        int k=0;
        while(!pq.empty())
        {
            int indx=pq.top().second;
            pq.pop();
            k++;
            if(k==1)
            {
                ans[indx]="Gold Medal";
            }
            else if(k==2)
            {
                ans[indx]="Silver Medal";
            }
            else if(k==3)
            {
                ans[indx]="Bronze Medal";
            }
            else{
                ans[indx]=to_string(k);
            }
        }
        return ans;
    }
};