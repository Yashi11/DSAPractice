class Solution {
public:
    int i = 0;                                                
    string repeat(string s, int times) {                     
        for(int n = s.length(); --times; s += s.substr(0, n));
        return s;
    }

// RECURSION SOLUTION
    // string decodeString(string& s) {
    //     string ans = "", n = "";
    //     while(i < s.length() && s[i] != ']') {                
    //         for(; i < s.length() && isalpha(s[i]); i++)         
    //             ans += s[i]; 
    //         if(i >= s.length() || s[i] == ']') continue;         
    //         for(n = ""; i < size(s) && isdigit(s[i]); i++)    
    //             n += s[i];
    //         i++;                                           
    //         ans += repeat(decodeString(s), stoi(n));          
    //         i++;                                              
    //     } 
    //     return ans;
    // }

// STACK SOLUTION
    string decodeString(string& s){
        stack<pair<int,string>> st;
        string ans="";string num="";
        for(auto c:s){
            if(isalpha(c)) ans+=c;
            else if(isdigit(c)) num+=c;
            else if(c=='['){ st.push(make_pair(stoi(num),ans));// st.push(make_pair(stoi(move(num)),move(ans)))
            num="";ans="";   //move means copy here and empty string..
            }
            else{
            int cnt=st.top().first;
            string prev=st.top().second;
            st.pop();
            ans=prev+repeat(ans,cnt);
            }
        }
        return ans;
    }
};