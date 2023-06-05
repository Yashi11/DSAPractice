// O(N) + O(N) Solution
// class Solution {
// public:
//     bool isValidSerialization(string preorder) {
//         if(preorder=="#") return true;
//         preorder+=',';
//         int n=preorder.length();
//         stack<int> st;
//         string curr="";
//         for(int i=0;i<preorder.length();i++)
//         {
//             if(preorder[i]==',')
//             {
                
//                 if(curr=="#")
//                 {
//                     if(st.empty()) return false;
//                     st.top()--;
//                     while(!st.empty() && st.top()==0){
//                         st.pop();
//                         if(st.empty()) return i==n-1;
//                         st.top()--;
//                     }
//                     curr.clear();
//                     continue;
//                 }
//                 st.push(2);
//                 curr.clear();
//             }
//             else{
//                 curr+=preorder[i];   
//             }
//         }
//         cout<<st.top();
//         if(st.empty()) return true;
//         else return false;
//     }
// };

// O(N) + O(1) Solution
class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder+=',';
        int n=preorder.length();
        int nodes=1;
        for(int i=0;i<preorder.length();i++)
        {
           if(preorder[i]!=',') continue;
           nodes--;
           if(nodes<0) return false;
           if(preorder[i-1]!='#') nodes+=2;
        }
        
        return nodes==0;
    }
};