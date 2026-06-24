class MyQueue {
private:
    stack<int> s1, s2;
public:
    MyQueue() {}
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1;

        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.empty() ? -1 : s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};
