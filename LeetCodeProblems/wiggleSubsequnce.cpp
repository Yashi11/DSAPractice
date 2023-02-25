// DYNAMIC PROGRAMMING SOUTION
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
//         int inc=1;
//         int dec=1;
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i]>nums[i-1]) inc=dec+1;
//             else if(nums[i]<nums[i-1]) dec=inc+1;
//         }
//         return max(inc,dec);
//     }
// };

// GREEDY ALGORITHM SOLUTION
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return 1;
        int cnt=0;
        if(nums[0]!=nums[1]) cnt=2;
        else cnt=1;
        int prevD=nums[1]-nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int currD=nums[i]-nums[i-1];
            if((currD>0 && prevD<=0)||(currD<0 && prevD>=0)){
                 cnt++;
                 prevD=currD;
                 }
        }
        return cnt;

    }
};