class MyQueue {
    int front;
    vector<int> st;
public:
    MyQueue() {
        front = 0;
    }

    void push(int x) {
        st.push_back(x);
    }

    int pop() {
        return st[front++];
    }

    int peek() {
        return st[front];
    }

    bool empty() {
        return front >= st.size();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */