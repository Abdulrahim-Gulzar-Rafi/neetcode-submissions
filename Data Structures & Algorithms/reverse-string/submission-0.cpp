class Solution {
public:
    void reverseString(vector<char>& s) {
        const int n = static_cast<int>(s.size());
        for (int i = 0, j = n-1; i < n/2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};