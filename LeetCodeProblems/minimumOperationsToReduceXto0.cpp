// Recurssive Naive Solution
// class Solution {
// public:
//     int helper(vector<int>& nums,int x,int st,int en)
//     {
        
//         if(x==0) return 0;
//         if(st>en) return -1;
//         int n=en-st+1;
//         int ans1=-1;
//         if(nums[st]<=x) ans1 = helper(nums,x-nums[st],st+1,en);
//         int ans2=-1;
//         if(nums[en]<=x) ans2=helper(nums,x-nums[en],st,en-1);
//         if(ans1==-1 && ans2==-1) return -1;
//         else if(ans1==-1) return ans2+1;
//         else if(ans2==-1) return ans1+1;
//         else return min(ans1,ans2)+1;
//     }
//     int minOperations(vector<int>& nums, int x) {
//         return helper(nums,x,0,nums.size()-1);
//     }
// };

// Unordered Map Approach= O(N) time (Can also be done with binary search in O(NlogN) time
class Solution {
public:
//894887480
// [1241,8769,9151,3211,2314,8007,3713,5835,2176,8227,5251,9229,904,1899,5513,7878,8663,3804,2685,3501,1204,9742,2578,8849,1120,4687,5902,9929,6769,8171,5150,1343,9619,3973,3273,6427,47,8701,2741,7402,1412,2223,8152,805,6726,9128,2794,7137,6725,4279,7200,5582,9583,7443,6573,7221,1423,4859,2608,3772,7437,2581,975,3893,9172,3,3113,2978,9300,6029,4958,229,4630,653,1421,5512,5392,7287,8643,4495,2640,8047,7268,3878,6010,8070,7560,8931,76,6502,5952,4871,5986,4935,3015,8263,7497,8153,384,1136]
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> up;
        int ans=INT_MAX;
        int sum=0;
        up[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            up[sum]=i;
            if(sum==x) ans=min(ans,i+1);
        }
        sum=0;
        
        int n=nums.size();
        for(int e=n-1;e>=0;e--)
        {
            sum+=nums[e];
            if(up.find(x-sum)!=up.end())
            {
                if(up[x-sum]<e) ans = min(n-e+up[x-sum]+1,ans);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};