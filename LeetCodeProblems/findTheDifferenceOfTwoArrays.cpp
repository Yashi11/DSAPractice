class Solution {
public:
    int N=2001;
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> trk1(N,false);
        vector<bool> trk2(N,false);
        vector<int> ans1;
        vector<int> ans2;

        for(int i=0;i<nums1.size();i++)
        {
            trk1[nums1[i]+1000]=true;
        }
        for(int i=0;i<nums2.size();i++)
        {
            trk2[nums2[i]+1000]=true;
        }
        for(int i=0;i<N;i++)
        {
            if(trk1[i] && !trk2[i])
            {
                ans1.push_back(i-1000);
            }
            if(!trk1[i] && trk2[i])
            {
                ans2.push_back(i-1000);
            }
        }
        return {ans1,ans2};
    }
};