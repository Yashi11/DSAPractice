class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(st.empty()){
                st.push(nums[i]);
            }
            else if(st.top()>nums[i])
            {
                if(i<n) ans[i]=st.top();
                st.push(nums[i]);
            }
            else{
                st.pop();
                i++;
            }
        }
        return ans;
    }
};