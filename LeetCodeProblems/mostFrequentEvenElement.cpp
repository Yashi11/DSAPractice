class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) mp[nums[i]]++;
        }
        int freq=0;
        int ele=-1;
        for(auto itr:mp)
        {
            if(itr.second>freq){
                ele=itr.first;
                freq=itr.second;
            }
            else if(itr.second==freq){
                if(itr.first<ele) ele=itr.first;
            }
        }
        return ele;
    }
};