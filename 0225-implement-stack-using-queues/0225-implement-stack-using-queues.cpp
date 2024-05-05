class MyStack {
public:
     queue<int> dq;
    MyStack() {
       
        
    }
    
    void push(int x) {
        dq.push(x);
        int n = dq.size();
        for(int i=0;i<n-1;i++){
            dq.push(dq.front());
            dq.pop();
        }
    }
    
    int pop() {
        int ans = dq.front();
        dq.pop();
        return ans;
    }
    
    int top() {
        return dq.front();
    }
    
    bool empty() {
        return dq.empty();
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