class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        int carry=0;
        vector<int> ans;
        
        while(k || carry)
        {
            int temp;
           
            if(i>=0) {
                 temp=(num[i]+carry+(k%10));
                 num[i]=temp%10;}
            else{
                temp=carry+(k%10);
                ans.push_back(temp%10);
            }
            // cout<<temp<<"&\n";
            carry=temp/10;
            k=k/10;
            i--;
        }
        for(int i=0;i<ans.size()/2;i++)
        {
            swap(ans[i],ans[ans.size()-i-1]);
        }
        for(int i=0;i<num.size();i++)
        {
            ans.push_back(num[i]);
        }
        return ans;
    }
};