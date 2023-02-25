class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> trk;
        for(int i=0;i<nums.size();i++)
        {
            trk.insert(nums[i]);
        }
        int len=0;
        for(int i=0;i<nums.size();i++)
        {
            if(trk.find(nums[i]-1)==trk.end())
            {
                int currNum=nums[i];
                int currLen=1;
                while(trk.find(currNum+1)!=trk.end())
                {
                    currNum++;
                    currLen++;
                }
                len=max(len,currLen);
            }
        }
        return len;
    }
};