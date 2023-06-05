class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int curr,vector<bool>& vis)
    {
        vis[curr]=true;
        for(auto e:rooms[curr])
        {
            if(!vis[e]) dfs(rooms,e,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        vis[0]=true;
        dfs(rooms,0,vis);
        for(auto i:vis){
            if(i==false) return false;
        }
        return true;
    }
};