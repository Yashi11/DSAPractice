class Solution {
public:
    int strStr(string haystack, string needle) {
     vector<int> indxs;
     for(int i=0;i<haystack.length();i++)
     {
         if(haystack[i]==needle[0] && i<=haystack.length()-needle.length()){
             indxs.push_back(i);
         }
     }
     for(int i=0;i<indxs.size();i++)
     {
         bool flag=true;
         for(int j=1;j<needle.length();j++)
         {
             if(haystack[indxs[i]+j]!=needle[j]) {flag = false; break;}
         }
         if(flag) return indxs[i];
     } 
     return -1;  
    }
};