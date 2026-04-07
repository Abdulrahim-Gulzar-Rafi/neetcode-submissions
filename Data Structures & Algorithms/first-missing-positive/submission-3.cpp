class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++) {
            while (nums[i]-1 < n && nums[i]-1 >= 0 && nums[i] != nums[nums[i] - 1] ) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int current = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != current) {
                return current;
            }
            current ++;
        }
        return current;
    }
};