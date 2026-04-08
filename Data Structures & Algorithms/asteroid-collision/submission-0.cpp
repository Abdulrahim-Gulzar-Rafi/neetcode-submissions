class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (const int& i: asteroids) {
            if (i > 0) {
                st.push_back(i);
            } else {
                const int current = abs(i);
                while (!st.empty() && st.back() > 0) {
                    if (current > st.back()) {
                        st.pop_back();
                    } else {
                        break;
                    }
                }
                if (st.empty() || st.back() < 0) {
                    st.push_back(i);
                } else if (!st.empty() && st.back() == current) {
                    st.pop_back();
                }
            }
        }
        return st;
    }
};