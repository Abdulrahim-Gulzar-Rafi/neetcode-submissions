class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        int actual_times_rotate = n - (k % n);
        int i;
        for (i = 0; i < actual_times_rotate; i++) {
            nums.push_back(nums[i]);
        }
        for (; i < n + actual_times_rotate; i++) {
            nums[i - actual_times_rotate] = nums[i];
        }
        while (actual_times_rotate --) {
            nums.pop_back();
        }
    }
};