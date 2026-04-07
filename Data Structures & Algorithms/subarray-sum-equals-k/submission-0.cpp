class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] ++;
        int sum = 0;
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int target = sum - k;
            total += mp[target];
            mp[sum] ++;
        }
        return total;
    }
};