class Solution {
public:
    void initialize(vector<int> stones,priority_queue<int,vector<int>>&pq)
    {
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
    }
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int,vector<int>> pq;
       initialize(stones,pq);
       while(pq.size()>1)
       {
           int heavy=pq.top();
           pq.pop();
           int light=pq.top();
           pq.pop();
           if(heavy-light>0) pq.push(heavy-light);
       }
       if(pq.size()==1) return pq.top();
       else return 0;
    }
};