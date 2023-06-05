class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        int minS=2;
        int maxS=9*D;
        if(S<minS || S>=maxS) return "-1";
        string ans(D,'0');
        ans[0]='1';
        S=S-1;
        for(int i=D-1;i>=0;i--)
        {
            if(S-9>0){
                ans[i]='9';
                S-=9;
            }
            else if(S-9<=0){
                ans[i]=S+ans[i];
                S=0;
            }
        }
        string ansF=ans;
        for(int i=ansF.length()-1;i>=0;i--)
        {
            if(ansF[i]<'9' && ansF[i]>='0'){
               if(i!=ansF.length()-1){ ansF[i]=ansF[i]+1;
                ansF[i+1]=ansF[i+1]-1;}
                else{
                    ansF[i]=ansF[i]-1;
                ansF[i-1]=ansF[i-1]+1;
                }
                break;
            }
        }
        return ansF;
    }
};