class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int max_count = 0;
        int previous_element = INT_MAX;
        bool first = true;
        int maxlen = 0, len = 0;
        for (const int& i: st) {
            if (first) {
                len = 1;
                first = false;
            } else {
                if (i - previous_element == 1) {
                    len ++;
                } else {
                    len = 1;
                }
            }
            maxlen = max(maxlen, len);
            previous_element = i;
        }
        return maxlen;
    }
};
