class StockSpanner {
    stack<pair<int,int>> st;
    int i;
public:
    StockSpanner() {
        i = 0;
    }

    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int span = i;
        if (!st.empty()) {
            span = (i - st.top().second);
        }
        i++;
        st.push({price,i});
        return span + 1;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */