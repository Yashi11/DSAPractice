class Solution {
public:
   
    bool uniqueOccurrences(vector<int>& arr) {
         vector<int> trk(2001,0);
        set<int> mySet;
        for(int i=0;i<arr.size();i++)
        {
            trk[arr[i]+1000]++;
        }
        for(int i=0;i<trk.size();i++)
        {
            if(trk[i]==0) continue;
            if(mySet.find(trk[i])==mySet.end()) mySet.insert(trk[i]);
            else return false;
        }
        return true;
    }
};