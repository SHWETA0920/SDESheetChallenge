class MinStack {
public:
    stack<long long>st;
    long long min;
    MinStack() {
        min =LLONG_MAX;
        
    }    
    void push(int val) {
        long long x= (long long) val;
        if(st.size()==0) {st.push(x);
        min =x;
        }
        else if(x>=min) st.push(x);
        else{
            long long old=2*x-min;
            st.push(old);
            min =x;
        }
    }
    
    void pop() {        
        if(st.top()<min){
            long long y = 2*min -st.top();
            min=y;
            st.pop();
        }
        else st.pop();
        
    }
    
    int top() {
        if(st.top()>=min) return (int)st.top();
        else return (int)min;
        
    }
    
    int getMin() {
        return int(min);
        
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
