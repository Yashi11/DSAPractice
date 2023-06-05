//Kinda Imp and good question
class Solution {
public:
    int countBinarySubstrings(string s) {
     int cnt=0;
     int prev=0;
     int curr=1;
     for(int i=1;i<s.length();i++)
     {
         if(s[i-1]!=s[i])
         {
             cnt+=min(curr,prev);
             prev=curr;
             curr=1;
         }
         else{
             curr++;
         }
     }  
     return cnt+=min(curr,prev);
    }
};