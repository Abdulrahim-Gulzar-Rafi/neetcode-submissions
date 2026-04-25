class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int n = static_cast<int>(word1.size()), n2 = static_cast<int>(word2.size());
        int i = 0, i2 = 0;
        string result;
        while (i < n && i2 < n2) {
            result.push_back(word1[i]);
            result.push_back(word2[i2]);
            i++; i2++;
        }
        while (i < n) {
            result.push_back(word1[i]);
            i++;
        }
        while (i2 < n2) {
            result.push_back(word2[i2]);
            i2++;
        }
        return result;
    }
};