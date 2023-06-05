class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        vector<int> last_occur(26,-1);
        for(int i=0;i<n;i++)
        {
            last_occur[s[i]-'a']=i;
        }
        stack<char> st;
        vector<bool> seen(26,false);
        for(int i=0;i<n;i++)
        {
            int curr=s[i]-'a';
            if(seen[curr]) continue;
            while(!st.empty() && st.top()>s[i] && i<last_occur[st.top()-'a']){
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            seen[curr]=true;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
       return res;
    }
};