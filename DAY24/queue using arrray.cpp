class myQueue {
private:
    vector<int> arr;
    int front, rear, size, cap;

public:
    myQueue(int n) {
        cap = n;
        arr.resize(n);
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }

    void enqueue(int x) {
        if (isFull()) return;
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }

    void dequeue() {
        if (isEmpty()) return;
        front = (front + 1) % cap;
        size--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};
