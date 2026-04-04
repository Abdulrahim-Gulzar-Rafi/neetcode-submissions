class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int n = static_cast<int>(nums.size());
        vector<vector<int>> freq(n+1);
        for (int i = 0; i < n; i++) {
            count[nums[i]] ++;
            freq[count[nums[i]]].push_back(nums[i]);
        }
        unordered_set<int> distinct_k;
        vector<int> ans;
        for (int i = n; i >= 0; i--) {
            for (int elem: freq[i]) {
                distinct_k.insert(elem);
                if (distinct_k.size() == k) {
                    ans = vector(distinct_k.begin(), distinct_k.end());
                    return ans;
                }
            }
        }
        return ans;
    }
};
