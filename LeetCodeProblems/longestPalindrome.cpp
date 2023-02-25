class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> trk(52,0);
        for(int i=0;i<s.length();i++)
        {
            if(islower(s[i])) trk[s[i]-'a']++;
            else trk[s[i]-'A'+ 25]++;
        }
        int ans=0;
       bool flag=false;
        for(int i=0;i<52;i++)
        {
           if(trk[i]%2==0) ans+=trk[i];
           else{
               flag=true;
               ans+=(trk[i]/2)*2;
           }
        }
        return flag?ans+1:ans;
    }
};