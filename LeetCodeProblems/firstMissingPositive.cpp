class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       //store all digits in unordered set--> avg O(1) worst O(N)
       //pointer from 1 increament if digit is present 
       //but the problem is unordered set doesnt uses constant space
       unordered_set<int> us;
       for(int i=0;i<nums.size();i++)
       {
           us.insert(nums[i]);
       } 
       int cnt=1;
       while(us.find(cnt)!=us.end())
       {
           cnt++;
       }
       return cnt;
    }
};