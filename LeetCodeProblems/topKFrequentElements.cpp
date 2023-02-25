class Compare {
public:
    bool operator()(pair<int,int> below, pair<int,int> above)
    {
        if (below.second < above.second) {
            return true;
        } 
        return false;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end()) mp[nums[i]]++;
            else mp[nums[i]]=1;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            pq.push({itr->first,itr->second});
        }

        vector<int> ans;
        while(k--)
        {
            pair<int,int> temp=pq.top();
            ans.push_back(temp.first);
            pq.pop();
        }
        return ans;
    }
};