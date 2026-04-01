class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int n = static_cast<int>(nums.size());
        int count = 0;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] != val) {
                break;
            }
            count ++;
        }
        for (int i = 0; i < n; i++) {
            if (i >= n-count) {
                break;
            }
            while (nums[i] == val) {
                count ++;
                if (i >= n-count) {
                    break;
                }
                swap(nums[i], nums[n - count]);
            }
        }
        nums.resize(n-count);
        return nums.size();
    }
};