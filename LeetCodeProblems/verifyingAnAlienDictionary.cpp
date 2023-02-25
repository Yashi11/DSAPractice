class Solution {
public:
   
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> mp;
        for(int i=0;i<order.length();i++)
        {
            mp[order[i]]=i+1;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            string curr=words[i];
            string next=words[i+1];
            bool flag=false;
            for(int j=0;j<min(curr.length(),next.length());j++)
            {
                if(mp[curr[j]]>mp[next[j]]) return false;
                else if(mp[curr[j]]<mp[next[j]]) {flag=true;break;}
            }
            if(!flag){
                if(curr.length()>next.length()) return false;
            }
        }
        return true;
    }
};