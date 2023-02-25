class Solution {
public:
    string repeat(string s,int n){
        string ans="";
        while(n--){
            ans+=s;
        }
        return ans;
    }
    string gcdOfStrings(string str1, string str2) {
        for(int l=min(str1.length(),str2.length());l>0;l--)
        {
            string temp=str1.substr(0,l);
            if(str1.length()%l==0 && str2.length()%l==0)
            {
                if(repeat(temp,str1.length()/l)==str1 && repeat(temp,str2.length()/l)==str2 ) return temp;
            }
        }
        return "";
    }
};