class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            int st=0;
            for(int i=0;i<n-1;i++)
            {
                if(a[i]%2==a[i+1]%2) continue;
                else{
                    sort(a.begin()+st,a.begin()+i+1,greater<int>{});
                    st=i+1;
                }
            }
            sort(a.begin()+st,a.end(),greater<int>{});
            return a;
        }
        
};