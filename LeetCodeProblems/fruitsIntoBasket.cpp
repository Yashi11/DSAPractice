class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> us;
        int ans=0;
        int i=0;
        int j=0;
        while(i<=j && j<fruits.size())
        {
            us[fruits[j]]++;
            if(us.size()<2)
            {
                ans=max(ans,j-i+1);
                j++;  
            }
            else if(us.size()==2)
            {
               ans=max(ans,j-i+1);
               j++;
            }
            else
            {
                while(us.size()>2)
                {
                    us[fruits[i]]--;
                    if(us[fruits[i]]==0) {us.erase(fruits[i]);j++;}
                    i++;
                }
            }

        }
        return ans;
    }
};