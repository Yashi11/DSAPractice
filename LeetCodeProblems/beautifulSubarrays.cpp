// class Solution {
// public:
//     long long beautifulSubarrays(vector<int>& nums) {
//         int cnt=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             int prevXor=nums[i];
//             if(prevXor==0) cnt++;
//             for(int j=i+1;j<n;j++)
//             {
//                 prevXor=nums[j]^prevXor;
//                 if(prevXor==0) cnt++;
//             }
//         }
//         return cnt;
//     }
// };