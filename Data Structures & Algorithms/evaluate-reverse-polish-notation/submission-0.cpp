class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<pair<string, int>> st;

        auto is_number = [&](const string &token) -> pair<int,bool> {
            if (token.length() > 1) {
                return {stoi(token), true};
            }
            if (!isdigit(token.back())) {
                return {0,false};
            }
            return {token.back() - '0', true};
        };

        auto get_result = [&](const int a, const int b, const string &operation) -> int {
            if (operation == "+") {
                return a + b;
            }
            if (operation == "-") {
                return a - b;
            }
            if (operation == "*") {
                return a * b;
            }
            return a / b;
        };

        for (auto & token : tokens) {
            auto [fst, snd] = is_number(token);
            if (st.size() >= 2) {
                pair<string,int> previous = st.top();
                st.pop();
                pair<string,int> previous2 = st.top();
                st.pop();
                if (snd && !previous.first.empty() && previous2.first.empty()) {
                    st.emplace("", get_result(fst, previous2.second, previous.first));
                } else if (!snd && previous.first.empty() && previous2.first.empty()) {
                    st.emplace("", get_result(previous2.second, previous.second, token));
                } else {
                    st.push(previous2);
                    st.push(previous);
                    st.emplace(snd ? "" : token, snd ? fst : 0);
                }
            } else {
                if (snd) {
                    st.emplace("", fst);
                } else {
                    st.emplace(token, 0);
                }
            }
        }
        return st.top().second;
    }
};
