//  APPROACH 1: TLE 
// class Solution {
//   public:
//     void mark(int num,vector<int>& track)
//     {
//         for(int i=num;i<track.size();i+=num)
//         {
//             track[i]++;
//         }
//     }
//     int countSpecialNumbers(int n, vector<int> arr) {
//         // Code here
//         int maxm=0;
//         for(int i=0;i<n;i++)
//         {
//             maxm=max(maxm,arr[i]);
//         }
//         vector<int> track(maxm+1,0);
//         for(int i=0;i<n;i++)
//         {
//             mark(arr[i],track);
//         }
        
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             if(track[arr[i]]>1) ans++;
//         }
//         return ans;
//     }
// };

// APPROACH 2
class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        map<int,int> mp;
        for(int i=0;i<N;i++) mp[arr[i]]++;
        auto isSpecial = [&] (int x)-> auto{
            for(int i=2;i*i<=x;i++)
            {
                if(x%i==0){
                    if(mp[i] or mp[x/i]) return true;
                }
            }
            return false;
        };
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(isSpecial(arr[i]) || mp[arr[i]]>1) ans++;
        }
        if(mp[1]) ans=N-(mp[1]==1);
        return ans;
    }
};