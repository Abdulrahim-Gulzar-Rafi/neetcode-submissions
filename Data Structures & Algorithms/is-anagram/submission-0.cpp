class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for (const char& c: s) {
            mp[c] --;
        }
        for (const char& c: t) {
            if (!mp.count(c)) {
                return false;
            }
            mp[c] ++;
            if (mp[c] > 0) {
                return false;
            }
        }
        for (auto& i: mp) {
            if (i.second != 0) {
                return false;
            }
        }
        return true;
    }
};
