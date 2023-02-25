class Solution {
public:
    vector<int> diStringMatch(string s) {
        int st=0;
        int en=s.length();
        vector<int> ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I'){
                ans.push_back(st);
                st++;
            }
            else if(s[i]=='D')
            {
                ans.push_back(en);
                en--;
            }
        }
        ans.push_back(st);
        return ans;
    }
};