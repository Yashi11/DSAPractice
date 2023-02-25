// O(N^3) Time Complexity Soln

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxLen=0;
//       for(int i=0;i<s.length();i++)
//       {
//           for(int j=i;j<s.length();j++)
//           {
//               unordered_set<char> us;
//               bool flag=true;
//               for(int k=i;k<j;k++)
//               {
//                   if(us.find(s[k])!=us.end()) flag=false;
//                   else us.insert(s[k]);
//               }
//               if(flag) maxLen=max(maxLen,j-i);
//           }
//       } 
//       return maxLen; 
//     }
// };

// O(N^2) Time Complexity Soln

class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxLen=0;
//       for(int i=0;i<s.length();i++)
//       {
//           unordered_set<char> us;
//           for(int j=i;j<s.length();j++)
//           {
//               if(us.find(s[j])!=us.end()) break;
//               else{
//                   us.insert(s[j]);
//                   maxLen=max(maxLen,j-i+1);
//               }
//           }
//       } 
//       return maxLen; 
//     }
// };

//O(2*N) Time Complexity Solution

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxLen=0;
//       unordered_set<char> us;
//       int l=0;int r=0;
//       while(l<=r && r<s.length())
//       {
//         if(us.find(s[r])!=us.end()){
//             us.erase(s[l]);
//             l++;
//         }
//         else{
//             us.insert(s[r]);
//             maxLen=max(maxLen,r-l+1);
//             r++;
//         }
//       }
//       return maxLen; 
//     }
// };

//O(N) Time Complexity

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
      unordered_map<char,int> us;
      int l=0;int r=0;
      while(r<s.length())
      {
        if(us.find(s[r])!=us.end()){
            l=max(l,us[s[r]]+1);
        }
       us[s[r]]=r;
       maxLen= max(maxLen,r-l+1);
       r++;
      }
      return maxLen; 
    }
};