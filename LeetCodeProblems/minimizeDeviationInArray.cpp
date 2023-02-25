class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       priority_queue<int> pq;
       int minVal = INT_MAX;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]%2==1) nums[i]*=2;
           pq.push(nums[i]);
           minVal=min(minVal,nums[i]);
       }
       int minDeviation=INT_MAX;
       while(true)
       {
           int maxVal=pq.top();
           pq.pop();
           minDeviation=min(minDeviation,maxVal-minVal);
           if(maxVal%2==1) break;
           maxVal/=2;
           minVal=min(minVal,maxVal);
           pq.push(maxVal);
       }
       return minDeviation;
    }
};