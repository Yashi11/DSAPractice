class Solution {
public:
    int helper(string s,int i,int mulp)
    {
        long long int ans=0;
        for(int j=i;j<s.length();j++)
        {
            if(s[j]>='0' && s[j]<='9')
            {
                if(mulp==1 && ans*10 + (s[j]-'0')>INT_MAX) return INT_MAX;
                else if(mulp==-1 && (ans*10 +(s[j]-'0'))*mulp<INT_MIN ) return INT_MIN;
                ans=ans*10 +(s[j]-'0');
            }
            else break;
        }
        cout<<ans;
        return mulp*ans;
    }
    int myAtoi(string s) {
        bool signTrk=false;
        int ans=0;
        int mulp=1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ' && !signTrk) continue;
            else if(s[i]=='+' || s[i]=='-')
            {
               if(signTrk) return ans;
                else{
                    signTrk=true;
                    if(s[i]=='-') mulp=-1;
                }
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                return helper(s,i,mulp);
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};