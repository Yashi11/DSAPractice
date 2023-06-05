class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans=0;
        long long int zeroes=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zeroes++;
            }
            else{
                ans+=(zeroes*(zeroes+1))/2;
                zeroes=0;
            }
        }
        ans += (zeroes*(zeroes+1))/2;
        return ans;
    }
};