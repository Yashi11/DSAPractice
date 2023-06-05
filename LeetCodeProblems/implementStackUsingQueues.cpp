class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(!q2.empty()) swap(q1,q2);
        q1.push(x);
    }
    
    int pop() {
       int last;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        last=q1.front();
        q1.pop();
        swap(q1,q2);
        return last;
    }
    
    int top() {
        int last;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        last=q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1,q2);
        return last;
    }
    
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */