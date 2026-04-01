class Solution {
    int search(unordered_set<int>& st, unordered_map<int,int>& mp, int at) {
        if (!st.count(at)) {
            return 0;
        }
        if (mp.count(at)) {
            return mp[at];
        }
        int result = search(st, mp, at -1) + 1;
        mp[at] = result;
        return result;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxlen = 0;
        unordered_map<int,int> mp;
        for (auto i: st) {
            if (mp.count(i)) {
                maxlen = max(maxlen, mp[i]);
            } else {
                maxlen = max(maxlen, search(st, mp, i));
            }
        }
        return maxlen;
    }
};
