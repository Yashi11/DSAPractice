class Compare{
    public:
    bool operator() (pair<char,int> above,pair<char,int> below)
    {
        if(above.second<below.second) return true;
        else return false;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,Compare> pq;
        map<char,int>mp;
       for(int i=0;i<s.length();i++)
       {
           if(mp.find(s[i])==mp.end()){ mp[s[i]]=1;}
           else{
               mp[s[i]]++;
           }
       } 
       for(auto itr=mp.begin();itr!=mp.end();itr++)
       {
           pq.push(make_pair(itr->first,itr->second));
       }
       string ans="";
       while(!pq.empty())
       {
           ans = ans + string(pq.top().second,pq.top().first);
           pq.pop();
       }
       return ans;
    }
};