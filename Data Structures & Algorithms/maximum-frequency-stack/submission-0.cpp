class FreqStack {
    unordered_map<int,int> mp;
    unordered_map<int, list<int>> counts;
    int max_freq;
public:
    FreqStack() {
        max_freq = 0;
    }

    void push(int val) {
        mp[val] ++;
        counts[mp[val]].push_back(val);
        max_freq = max(max_freq, mp[val]);
    }

    int pop() {
        const int result = counts[max_freq].back();
        counts[max_freq].pop_back();
        mp[result] --;
        if (counts[max_freq].empty()) {
            max_freq --;
        }
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */