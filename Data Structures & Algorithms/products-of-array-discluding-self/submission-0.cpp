class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix, suffix;
        int n = static_cast<int>(nums.size());
        prefix.reserve(nums.size());
        suffix.resize(nums.size());
        int j = n-1;
        for (int i = 0; i < n; i++) {
            if (prefix.empty()) {
                prefix.push_back(nums[i]);
            } else {
                prefix.push_back(nums[i] * prefix[i-1]);
            }
            if (j == n-1) {
                suffix[j] = nums[j];
            } else {
                suffix[j] = nums[j] * suffix[j + 1];
            }
            j--;
        }
        int left = -1, right = 1;
        for (int i = 0; i < n; i++) {
            int prod = 1;
            if (left >= 0) {
                prod *= prefix[left];
            }
            if (right < n) {
                prod *= suffix[right];
            }
            nums[i] = prod;
            left ++;
            right ++;
        }
        return nums;
    }
};
