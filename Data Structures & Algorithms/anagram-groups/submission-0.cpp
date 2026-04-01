class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> sorted_mp;
        for (int i = 0; i < strs.size(); i++) {
            string unsorted = strs[i];
            sort(strs[i].begin(), strs[i].end());
            sorted_mp[strs[i]].push_back(unsorted);
        }
        vector<vector<string>> ans;
        for (auto i: sorted_mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
