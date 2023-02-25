class Solution{
public:
string smallestNumber(int S, int D){
        // code here 
        if(S==0){
            if(D==1) return "0";
            else return "-1";
        }
        else if(S>9*D) return "-1";
        else{
            string ans="";
            for(int i=0;i<D;i++)
            {
                if(S>9){
                    S-=9;
                    ans+="9";
                }
                else{
                    if(i==D-1){
                        ans+=to_string(S);
                        S=0;
                    }
                    else{
                        ans+=to_string(S-1);
                        S=1;
                    }
                }
            }
            if(S>0) ans+=to_string(S);
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
};