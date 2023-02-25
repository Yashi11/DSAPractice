//NAIVE SOLN
// class Solution{
//   public:
//     bool checkS(string S)
//     {
//         for(int i=0;i<S.length();i++)
//         {
//             if(S[i]!='?' && S[i]==S[i+1]) return true;
//         }
//         return false;
//     }
//     int getMinimumDays(int N,string S, vector<int> &P,int i=0) {
//         // code here
//         int ans=0;
//         if(checkS(S))
//         {
//           S[P[i]]='?';
//           ans=1+getMinimumDays(N,S,P,i+1);
//         }
//         return ans;
//     }
// };

//OPTIMAL SOLN
class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        // code here
        int match = 0;
        for(int i = 0; i < N - 1; i++) {
            if(S[i] == S[i + 1]) match++;
        }
        
        if(match == 0) return 0;
        for(int day=0; day<N; day++)
        {
            int i = P[day];
            if(i+1<N && S[i]==S[i+1])
            {
                match--;
            }
            if(i>=0 && S[i-1]==S[i]) match--;
            
            S[i] = '?';
            
            if(!match) return day+1;
            
        }
        
        return 0;
    }
};