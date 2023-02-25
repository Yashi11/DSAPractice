
// BRUTE FORCE
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//      //brute force approach implement trial
//      vector<vector<string>> ans;
//      vector<bool> trk(strs.size(),false);
//      for(int i=0;i<strs.size();i++)
//      {
//         if(trk[i]) continue;
//         vector<int> arr(26,0);
//         for(int j=0;j<strs[i].length();j++)
//         {
//             arr[strs[i][j]-'a']++;
//         }
//         vector<string> currAns;
//         currAns.push_back(strs[i]);
//         trk[i]=true;
//         for(int j=i+1;j<strs.size();j++)
//         {
//             vector<int> arr2(26,0);
//             for(int k=0;k<strs[j].length();k++)
//             {
//                 arr2[strs[j][k]-'a']++;
//             }
//             if(arr2==arr)
//             {
//                 currAns.push_back(strs[j]);
//                 trk[j]=true;
//             }
//         }
//         ans.push_back(currAns);
//      }
//      return ans;

//     }
// };


// OPTIMAL 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        vector<vector<string>> ans={};
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(mp.find(temp)!=mp.end()){
                mp[temp].push_back(strs[i]);
            }
            else{
                mp[temp]={strs[i]};
            }
        }
        for(auto itr:mp){
            ans.push_back(itr.second);
        }
        return ans;
    }
};