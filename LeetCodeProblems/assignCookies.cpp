//OPTIMAL SOLN USING GREEDY
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0;
        int j=p.length()-1;
        vector<int> ans;
        unordered_map<char,int> mp1;
        for(int i=0;i<p.length();i++)
        {
            mp1[p[i]]++;
        }
        unordered_map<char,int> mp2;
        for(int i=0;i<p.length();i++)
        {
            mp2[s[i]]++;
        }
        while(j<s.length())
        {
            if(mp1==mp2) ans.push_back(i);
            if(mp1.find(s[i])!=mp1.end())mp2[s[i]]--;
            else mp2.erase(s[i]);
            i++;
            j++;
            mp2[s[j]]++;
        }
        return ans;
    }
};