class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int ans=0;
        int open=0;
        int close=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else close++;
            if(open==close)
            {
                ans=max(ans,open+close);
            }
            else if(close>open)
            {
                open=close=0;
            }
        }
        
        open=close=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else close++;
            if(open==close)
            {
                ans=max(ans,open+close);
            }
            else if(close<open)
            {
                open=close=0;
            }
        }
        return ans;
    }
};