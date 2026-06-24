class myStack {
private:
    vector<int> arr;
    int size;

public:
    myStack(int n) {
        size = n;
    }
    bool isEmpty() {
        return arr.size() == 0;
    }
    bool isFull() {
        return arr.size() == size;
    }
    void push(int x) {
        if (!isFull()) {
            arr.push_back(x);
        }
    }
    void pop() {
        if (!isEmpty()) {
            arr.pop_back();
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr.back();
        }
        return -1;
    }
};
