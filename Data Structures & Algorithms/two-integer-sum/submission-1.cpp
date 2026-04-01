class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = static_cast<int>(nums.size());
        vector<int> result;
        unordered_map<int,vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            int to_find = target - nums[i];
            if (mp.count(to_find)) {
                if (to_find == nums[i] && mp[to_find].size() > 1) {
                    result = mp[nums[i]];
                    break;
                }
                if (to_find != nums[i]) {
                    result = {mp[to_find][0], i};
                    break;
                }
            }
        }
        if (result[0] > result[1]) {
            swap(result[0], result[1]);
        }
        return result;
    }
};
