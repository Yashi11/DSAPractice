class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0) return n==1?n:-1;
       vector<bool> doesTrust(n,false);
       vector<int> isTrusted(n,0);
       for(int i=0;i<trust.size();i++)
       {
           doesTrust[trust[i][0]-1]=true;
           isTrusted[trust[i][1]-1]++;
       }
       for(int i=0;i<n;i++)
       {
           if(!doesTrust[i] && isTrusted[i]==n-1) return i+1;
       }

       return -1;
    }
};