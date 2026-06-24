#include <deque>
using namespace std;

class MyStack {
private:
    deque<int> dq;
public:
    MyStack() {
        
    }    
    void push(int x) {
        dq.push_back(x);
    }    
    int pop() {
        if (dq.empty()) return -1;
        int val = dq.back();
        dq.pop_back();
        return val;
    }
    
    int top() {
        if (dq.empty()) return -1;
        return dq.back();
    }
    
    bool empty() {
        return dq.empty();
    }
};
