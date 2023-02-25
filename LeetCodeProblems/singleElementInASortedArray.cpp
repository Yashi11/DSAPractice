// O(N) Bitwise XOR Approach
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//        int ans=nums[0];
//        for(int i=1;i<nums.size();i++)
//        {
//            ans=ans^nums[i];
//        } 
//        return ans;
//     }
// };

// O(logN) Binary Search Approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid;
        if(high==0) return nums[high];
        else if(nums[low]!=nums[low+1]) return nums[low];
        else if(nums[high]!=nums[high-1]) return nums[high];
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            else if((mid%2==0 && nums[mid]==nums[mid-1])||(mid%2==1 && nums[mid]==nums[mid+1])){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};