class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty()) st.push(arr[i]);
            else{
                if((st.top()>=0 && arr[i]<0)||(st.top()<0 && arr[i]>=0)) st.pop();
                else st.push(arr[i]);
            }
        }
        n = st.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};