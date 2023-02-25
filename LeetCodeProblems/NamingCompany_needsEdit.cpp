// NAIVE SOLUTION O(N^2) Time Complexity and O(N) space
// class Solution {
// public:
//     long long distinctNames(vector<string>& ideas) {
//        unordered_set<string> us;
//        int ans=0;
//        for(int i=0;i<ideas.size();i++)
//        {
//            us.insert(ideas[i]);
//        } 
//        for(int i=0;i<ideas.size()-1;i++)
//        {
//            for(int j=i+1;j<ideas.size();j++)
//            {
//                string s1=ideas[i];
//                string s2=ideas[j];
//                swap(s1[0],s2[0]);
//                if(us.find(s1)==us.end() && us.find(s2)==us.end()){
//                    ans+=2;
//                }
//            }
//        }
//        return ans;
//     }
// };

