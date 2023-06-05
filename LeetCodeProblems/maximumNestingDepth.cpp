class Solution {
public:
    int maxDepth(string s) {
	// O(N) Time + O(1) Space
    //    int ans=0;
    //    int curr=0;
    //    for(int i=0;i<s.length();i++){
    //        if(s[i]=='('){
    //           curr++;
    //           ans=max(ans,curr); 
    //        }
    //        else if(s[i]==')')
    //        {
    //            curr--;
    //            ans=max(ans,curr);
    //        }
    //    } 
    //    return ans;

	// O(N) Time + O(N) Space
       stack<int> st;
       int ans=0;
       for(int i=0;i<s.length();i++){
           if(s[i]=='('){
              st.push(1);
           }
           else if(s[i]==')')
           {
               st.pop();
           }
           int stackSize=st.size();
           ans=max(ans,stackSize);
       }
       return ans;
    }
};