class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> ans_map;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(st.empty()){
                ans_map[nums2[i]]=-1;
                st.push(nums2[i]);
                continue;
            }
            if(nums2[i]<st.top()){
                ans_map[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
            else{
                st.pop();
                i++;
            }
        }

        vector<int> ans;
        for(auto num:nums1)
        {
            ans.push_back(ans_map[num]);
        }
        return ans;
    }
};