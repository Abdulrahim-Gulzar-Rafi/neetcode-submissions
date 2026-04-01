class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int left = 0, right = n - 1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);
                left ++;
                i++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[right]);
                right --;
            }
        }
    }
};
