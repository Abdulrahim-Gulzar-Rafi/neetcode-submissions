class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_count = 0, max_elem = nums[0];
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && nums[i] == nums[j]) {
                j ++;
            }
            int count = j - i;
            if (count > max_count) {
                max_count = count;
                max_elem = nums[i];
            }
            i = j-1;
        }
        return max_elem;
    }
};