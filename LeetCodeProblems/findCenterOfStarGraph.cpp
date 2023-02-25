class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> degree;
        int mx=0;
        for(int i=0;i<edges.size();i++)
        {
            mx=max(mx,max(edges[i][0],edges[i][1]));
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        for(auto itr:degree)
        {
            if(itr.second==mx-1) return itr.first;
        }
        return -1;
    }
};