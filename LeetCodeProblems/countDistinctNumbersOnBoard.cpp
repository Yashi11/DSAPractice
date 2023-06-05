class Solution {
public:
//     void helper(vector<vector<int>>& trk)
//     {
//         int N=100;
//         for(int i=2;i<=100;i++)
//         {
//             vector<int> cAns;
//             for(int j=2;j<i;j++)
//             {
//                 if(i%j==1) cAns.push_back(j);
//             }
//             trk.push_back(cAns);
//         }
        
//     }
    int distinctIntegers(int n) {
        if(n==1) return 1;
        return n-1;
//         vector<vector<int>> trk;
//         trk.push_back({});
//         trk.push_back({});
//         helper(trk);
//         unordered_set<int> us;
//         queue<int> st;
//         st.push(n);
        
//         int ans=1;
//         while(!st.empty())
//         {
//             us.insert(st.front());
//             for(int i=0;i<trk[st.front()].size();i++)
//             {
//                 if(us.find(trk[st.front()][i])==us.end())
//                 {
//                   ans++;
//                     us.insert(trk[st.front()][i]);
//                     st.push(trk[st.front()][i]);
//                 }
//             }
//             st.pop();
//         }
//         return ans;
    }
};