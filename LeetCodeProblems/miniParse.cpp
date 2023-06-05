/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    bool isnumber(char c)
    { 
        return (c == '-') || isdigit(c); 
    };
    NestedInteger deserialize(string s) {
        stack<NestedInteger> st;
        st.push(NestedInteger());
        string curr="";
        for(auto c:s)
        {
            if(isnumber(c))
            {
                curr+=c;
            }
            else if(c==','){
                if(curr.length()>0 && !st.empty()) st.top().add(NestedInteger(stoi(curr)));
                curr.clear();
            }
            else if(c=='['){
                if(curr.length()>0 && !st.empty()) st.top().add(NestedInteger(stoi(curr)));
                curr.clear();
                st.push(NestedInteger());
            }
            else if(c==']'){
                if(curr.length()>0 && !st.empty()) st.top().add(NestedInteger(stoi(curr)));
                curr.clear();
                NestedInteger ni=st.top();
                st.pop();
                st.top().add(ni);
            }
        }
        if(curr.length()>0  && !st.empty()) st.top().add(NestedInteger(stoi(curr)));
        curr.clear();
        return st.top().getList().front();
    }
};