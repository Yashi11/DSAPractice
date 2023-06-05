class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> help;
        for(auto s:tokens)
        {
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int t1=help.top();
                help.pop();
                int t2=help.top();
                help.pop();
                int ans=0;
                if(s=="+")  ans=t2+t1;
                else if(s=="-") ans= t2-t1;
                else if(s=="*") ans=t2*t1;
                else ans=t2/t1;
                help.push(ans);
            }
            else{
                help.push(stoi(s));
            }
        }
        return help.top();
    }
};