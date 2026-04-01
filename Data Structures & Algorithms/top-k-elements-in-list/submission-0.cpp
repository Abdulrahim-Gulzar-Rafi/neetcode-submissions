class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] ++;
        }
        vector<pair<int,int>> v;
        for (auto [fst, snd]: mp) {
            v.push_back({snd, fst}); 
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        ans.reserve(k);
        for (int i = 0; i < k; i++) {
            ans.push_back(v.back().second);
            v.pop_back();
        }
        return ans;
    }
};
