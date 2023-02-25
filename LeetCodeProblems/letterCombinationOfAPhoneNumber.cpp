class Solution {
public:
    map<int,vector<char>> mp;
    Solution()
    {
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
    }
    void helper(string digits,vector<string>& ans,string currAns="",int i=0){
       if(i>=digits.length())
        {
            ans.push_back(currAns);
        }
        for(int j=0;j<mp[digits[i]].size();j++)
        {
            helper(digits,ans,currAns+mp[digits[i]][j],i+1);
        }  
    }
    vector<string> letterCombinations(string digits) {
       vector<string> ans={};
       if(digits.length()<1) return ans;
       helper(digits,ans);
        return ans; 
    }
};