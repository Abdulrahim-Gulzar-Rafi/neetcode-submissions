class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        const int n = static_cast<int>(strs.size());
        for (int i = 0; i < 202; i++) {
            char common = '0';
            for (int j = 0; j < n; j++) {
                if (i >= strs[j].size()) {
                    return prefix;
                }
                if (common == '0') {
                    common = strs[j][i];
                } else if (common != strs[j][i]) {
                    return prefix;
                }
            }
            prefix.push_back(common);
        }
        return prefix;
    }
};