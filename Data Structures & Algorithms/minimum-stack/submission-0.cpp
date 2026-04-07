class MinStack {
    stack<int> st;
    stack<int> mins;
public:
    MinStack() {

    }

    void push(int val) {
        st.push(val);
        if (mins.empty() || val <= mins.top()) {
            mins.push(val);
        }
    }

    void pop() {
        const int top = st.top();
        st.pop();
        if (top == mins.top()) {
            mins.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mins.top();
    }
};
