class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = static_cast<int>(s.length());
        for (const char& c: s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                if (st.size() > n / 2) {
                    return false;
                }
            } else {
                if (st.empty()) {
                    return false;
                }
                if (c == ')') {
                    if (st.top() == '(') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else if (c == ']') {
                    if (st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    if (st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};
