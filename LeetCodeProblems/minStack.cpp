class MinStack {
public:
    stack<long> st;
    long minEle;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) {st.push(val);minEle=val;}
        else if(val<minEle){
            st.push((2*(long)val)-minEle);
            minEle=val;
        }
        else st.push(val);
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top()<minEle){
            minEle=2*minEle-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
         if(st.top()<minEle){
            return minEle;
        }
        return st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */