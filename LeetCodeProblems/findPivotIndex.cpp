class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sLeft=0;
        int sRight=0;
        for(int i=0;i<nums.size();i++) sRight+=nums[i];
        vector<int> diffs(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            sRight=sRight-nums[i];
            diffs[i]=sRight-sLeft;
            sLeft+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(diffs[i]==0) return i;
        }
        return -1;

    }
};