class Solution {
public:
    int compress(vector<char>& chars) {
       string s="";
       int currCnt=1;
       int i;
       for(i=1;i<chars.size();i++)
       {
           if(chars[i]==chars[i-1])
           {
               currCnt++;
           }
           else{
               s= s+chars[i-1];
               if(currCnt>1) s=s+to_string(currCnt);
               currCnt=1;
           }
       }
       s = s+chars[i-1];
       if(currCnt!=1)s = s+to_string(currCnt);
       chars.clear();
       cout<<s;
       for(int i=0;i<s.length();i++)
       {
           chars.push_back(s[i]);
       }
       return chars.size();
    }
};