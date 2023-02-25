class Solution {
public:
    bool isSubsequence(string s, string t,string curr="",int i=0) {
        int sPointer=0;
        int tPointer=0;
        while(sPointer<s.length() && tPointer<t.length())
        {
            if(s[sPointer]==t[tPointer]){
                sPointer++;tPointer++;
            }
            else{
                tPointer++;
            }
        }
        if(sPointer==s.length()) return true;
        return false;
    }
};