class Solution {
public:
    // [9,2,5,4] [2,4,5,9] i->0 j->1
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()/2;
        int marked=0;
        while(i<nums.size()/2 && j<nums.size())
        {
            if((double)nums[i]<=(double)nums[j]/2){
                i++;
                j++;
                marked+=2;
            }
            else if((double)nums[i]> (double)nums[j]/2) {
                j++;
            }
        }
        return marked;
    }
};