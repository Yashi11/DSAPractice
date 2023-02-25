// O(N) Time and Space Complexity
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> uMap;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(uMap.find(nums[i])!=uMap.end())
//             {
//                 uMap[nums[i]]++;
//             }
//             else{
//                 uMap[nums[i]]=1;
//             }
//         }
//         for(auto itr:uMap){
//             if(itr.second>nums.size()/2) return itr.first;
//         }
//         return -1;
//     }
// };



//O(N) Time Complexity and O(1) space complexity

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int mjr=nums[0];
      int vote=0;
      for(int i=0;i<nums.size();i++)
      {
          if(nums[i]==mjr){vote++;}
          else if(nums[i]!=mjr){
              vote--;
          }
          if(vote==0){ mjr=nums[i];vote++;}
          
      }  
      return mjr;
    }
};
