class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.length()<=0 || words.size()<=0) return ans;
        unordered_map<string,int> mp1;
        for(auto w:words){
            mp1[w]++;
        }
        int wordLength=words[0].length();
        int totalWords=words.size();
        if(s.length()<wordLength*totalWords) return ans;
        for(int i=0;i<=s.length()-wordLength*totalWords;i++)
        {
            unordered_map<string,int> mp2;
            for(int j=0;j<words.size();j++)
            {
                int wordIndx=i+(j*wordLength);
                string word=s.substr(wordIndx,wordLength);
                if(mp1.find(word)==mp1.end()) break;
                mp2[word]++;
                if(mp2[word]>mp1[word]) break;
                if(j+1==totalWords) ans.push_back(i);
            }
        }
        return ans;
    }
};