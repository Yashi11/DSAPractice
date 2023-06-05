// TRIVIAL SOLN O(N^2)+O(1)
// class Solution {
// public:
//     int minLength(string s) {
//         int n=s.length();
//         string newS="";
//         bool changed=false;
//         for(int i=0;i<n;i++)
//         {
//             if((s[i]=='A' && i+1<n && s[i+1]=='B')||(s[i]=='C' && i+1<n && s[i+1]=='D')){
//                 changed=true;
//                 i++;
//                 continue;
//             }
//             else{
//                 newS=newS+s[i];
//             }

//         }
//         if(changed) return minLength(newS);
//         else return newS.length();
//     }
// };


// STACK SOLUITON O(N)+O(N)
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(!st.empty() && st.top()=='A' && s[i]=='B')  st.pop();
            else if(!st.empty() && st.top()=='C' && s[i]=='D') st.pop();
            else st.push(s[i]);
        }
        return st.size();
    }
};