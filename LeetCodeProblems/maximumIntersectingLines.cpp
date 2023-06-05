// NAIVE APPROACH
// class Solution {
//   public:
//     int maxIntersections(vector<vector<int>> lines, int N) {
//         // Code here
//         map<int,int> trk;
//         int mx=0;
//         for(auto line:lines)
//         {
//             for(int i=line[0];i<=line[1];i++)
//             {
//                 trk[i]++;
//                 mx=max(mx,trk[i]);
//             }
//         }
//         return mx;
        
//     }
// };

// PREFIX SUM APPROACH
class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        map<int,int> mp;
        for(auto line:lines)
        {
            mp[line[0]]++;
            mp[line[1]+1]--;
        }
        int ans=1;
        int prefix=0;
        for(auto itr:mp)
        {
            prefix+=itr.second;
            ans=max(ans,prefix);
        }
        return ans;
    }
};