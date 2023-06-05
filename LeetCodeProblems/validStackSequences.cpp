class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        if(pushed.size()==0) return true;
        st.push(pushed[0]);
        int i=1;
        while(st.top()!=popped[0])
        {
            st.push(pushed[i]);
            i++;
        }
        bool ans=true;
        for(int j=0;j<popped.size();j++)
        {
            if(!st.empty() && popped[j]==st.top())
            {
                st.pop();
            }
            else if(i<pushed.size())
            {
                st.push(pushed[i]);
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};