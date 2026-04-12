class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> mp;
        const int n = static_cast<int>(position.size());
        for (int i = 0; i < n; i++) {
            mp.emplace_back(position[i], static_cast<double>(target - position[i]) / speed[i]);
        }
        sort(mp.begin(), mp.end());
        stack<double> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() < mp[i].second) {
                st.pop();
            }
            st.push(mp[i].second);
        }
        if (!st.empty()) {
            const double top = st.top();
            st.pop();
            while (!st.empty() && top == st.top()) {
                st.pop();
            }
            st.push(top);
        }
        return st.size();
    }
};
