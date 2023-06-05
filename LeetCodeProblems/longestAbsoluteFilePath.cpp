// class Solution {
// public:
// ///SEE EXAMPLE 2
//     bool isFile(string s)
//     {
//         bool foundDot=false;
//         for(auto c:s)
//         {
//             if(c=='.'){
//                 return true;
//             }
//         }
//         return foundDot;
//     }
//     int lengthLongestPath(string input) {
//        stack<pair<string,int>> st; //<path,level>
//        int lvl=0;
//        string curr="";
//        vector<string> finals;
//        //O(N^2)
//        for(int i=0;i<input.length();i++)
//        {
//            if(input[i]=='\n'){
//                if(!isFile(curr)) curr=curr+'/';
//                if(!st.empty()) if(st.top().second>=lvl) finals.push_back(st.top().first);
//                while(!st.empty() && st.top().second>=lvl)
//                {
//                    st.pop();
//                }
//                if(!st.empty()) curr=st.top().first+curr;
//                st.push(make_pair(curr,lvl));
//                lvl=0;
//                curr="";
//            }
//            else if(input[i]=='\t')
//            {
//                lvl++;
//            }
//            else{
//                curr=curr+input[i];
//            }
//        }
//        if(curr!=""){
//             if(!isFile(curr)) curr=curr+'/';
//                if(!st.empty()) if(st.top().second>=lvl) finals.push_back(st.top().first);
//                while(!st.empty() && st.top().second>=lvl)
//                {
//                    st.pop();
//                }
//                if(!st.empty()) curr=st.top().first+curr;
//                st.push(make_pair(curr,lvl));
//                lvl=0;
//                curr="";
//            finals.push_back(st.top().first+curr);
//        }
//        int ans=0;
//        for(auto s:finals){
//            cout<<s<<"\n";
//            int len=s.length();
//            if(isFile(s)) ans=max(ans,len);
//        }
//        return ans;
//     }
// };

class Solution {
public:
    int lengthLongestPath(string input) {
        input.push_back('\n');
       vector<int>levels(500,0);
       int len=0;
       int lvl=0;
       bool isFile=false;
       int ans=0;
       for(auto c:input)
       {
           switch(c)
           {
               case '\n':
                if(isFile){
                    int tmp=0;
                    for(int i=0;i<=lvl;i++)
                    {
                        tmp+=levels[i];
                    }
                    ans=max(ans,tmp+lvl);
                }
                    
                    isFile=false;
                    lvl=0;
                    len=0;
                    break;
               case '\t':
                lvl++;
                break;
               case '.':
                isFile=true;
               default :
                    len++;
                    levels[lvl]=len;
           }
       }
    return ans;
    }
};