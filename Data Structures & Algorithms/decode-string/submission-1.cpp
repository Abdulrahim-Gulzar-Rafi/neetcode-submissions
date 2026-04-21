class Solution {
    static string repeat(const std::string& s, int n) {
        std::string result;
        result.reserve(s.length() * n); // Pre-allocate memory for efficiency
        for (int i = 0; i < n; ++i) {
            result += s; // Or result.append(s);
        }
        return result;
    }
public:
    string decodeString(string s) {
        stack<int> st;
        stack<string> sst;
        const int n = static_cast<int>(s.length());
        string temp;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                string times;
                while (isdigit(s[i]) && i < n) {
                    times.push_back(s[i]);
                    i++;
                }
                i--;
                st.push(stoi(times));
                sst.push(temp);
                temp = "";
                i++;
            } else if (s[i] == ']') {
                const int t = st.top();
                st.pop();
                temp = repeat(temp, t);
                sst.top() += temp;
                temp = sst.top();
                sst.pop();
            } else {
                temp.push_back(s[i]);
            }
        }
        return temp;
    }

};