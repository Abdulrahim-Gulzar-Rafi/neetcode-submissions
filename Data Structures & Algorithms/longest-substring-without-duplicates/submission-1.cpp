class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        const int N = s.length();
        unordered_map<char, int> mp;
        int max_len = 0;
        while (left < N) {
            while (right < N) {
                if (mp.count(s[right])) {
                    max_len = max(max_len, right - left);
                    mp[s[right]] = right;
                    while (left < mp[s[right]]) {
                        mp.erase(s[left]);
                        left++;
                    }
                } else {
                    mp[s[right]] = right;
                }
                right++;
            }
            if (right == N) {
                max_len = max(max_len, right - left);
                break;
            }
            left++;
        }
        return max_len;

    }
};
