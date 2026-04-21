class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st;
        int n = static_cast<int>(path.length());
        for (int i = 0; i < n; i++) {
            while (i < n && path[i] == '/') {
                i++;
            }
            string dir = "";
            while (i < n && path[i] != '/') {
                dir.push_back(path[i]);
                i++;
            }
            if (dir.empty()) {
                break;
            }
            if (dir.length() == 2 && dir == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else if (dir.length() > 2 || dir != ".") {
                st.push_back(dir);
            }
        }
        string result = "/";
        while (!st.empty()) {
            result += st.front();
            result.push_back('/');
            st.pop_front();
        }
        if (result != "/") {
            result.pop_back();
        }
        return result;
    }
};