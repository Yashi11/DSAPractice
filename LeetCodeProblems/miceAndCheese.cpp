// OBJECTIVE: MAX(sigma(reward1 for 0->k) + sigma(reward2 for k+1->n))
	// = MAX(sigma(reward1 for 0->k) + sigma(reward2 for 0->n)-sigma(reward2 for 0->k))
		// = MAX(sigma(reward1-reward2 for 0->k) + sigma(reward2 for 0->n))
		// {sigma(reward2 for 0->n) IS CONSTANT}
			// = MAX(sigma(reward1-reward2 for 0->k))
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({reward1[i]-reward2[i],i});
        }
        int ans=0;
        while(k--)
        {
            int i=pq.top().second;
            pq.pop();
            ans+=reward1[i];
        }
        while(!pq.empty())
        {
            int i=pq.top().second;
            pq.pop();
            ans+=reward2[i];
        }
        return ans;
    }
};