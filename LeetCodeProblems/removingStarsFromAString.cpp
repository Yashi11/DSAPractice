class Solution {
public:
    string removeStars(string s) {
      stack<char> st;
      for(int i=0;i<s.length();i++)
      {
          if(st.empty()) st.push(s[i]);
          else{
              if(s[i]=='*') st.pop();
              else st.push(s[i]);
          }
      }  
      int n=st.size();
      string ans=string(st.size(),'-');
      for(int i=n-1;i>=0;i--)
      {
        ans[i]=st.top();
        st.pop();
      }
      return ans;
    }
};