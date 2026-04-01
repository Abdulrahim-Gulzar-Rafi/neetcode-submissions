class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int it = 0;
        while (it <= 200) {
            char c = '0';
            for (const string& s: strs) {
                if (it < s.length()) {
                    if (c == '0') {
                        c = s[it];
                    } else {
                        if (s[it] != c) {
                            return ans;
                        }
                    }
                } else {
                    return ans;
                }
            }
            if (c == '0') {
                return ans;
            }
            ans.push_back(c);
            it++;
        }
        return ans;
    }
};