class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = static_cast<int>(temperatures.size());
        st.emplace(102, n);
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= st.top().first) {
                st.pop();
            }
            int val = temperatures[i];
            temperatures[i] = st.top().second == n ? 0 : st.top().second - i;
            st.emplace(val, i);
        }
        return temperatures;
    }
};
