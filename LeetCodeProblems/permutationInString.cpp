class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int i=0;
        int j=s1.length()-1;
        unordered_map<char,int> mp1;
        for(int i=0;i<s1.length();i++)
        {
            mp1[s1[i]]++;
        }
        unordered_map<char,int> mp2;
        for(int k=i;k<=j;k++){
            mp2[s2[k]]++;
        }
        while(j<s2.length()){
            if(mp2==mp1) return true;
            if(mp1.find(s2[i])==mp1.end())mp2.erase(s2[i]);
            else mp2[s2[i]]--;
            i++;
            j++;
            mp2[s2[j]]++;
        }
        return mp2==mp1;
    }
};