class Solution {
public:
    int findMin(vector<int> &nums) {
        const int N = static_cast<int>(nums.size());
        int left = 0, right = N-1;
        while (left < right) {
            if (right == left + 1) {
                return min(nums[right], nums[left]);
            }
            const int mid = (left + right) / 2;
            if (nums[left] < nums[mid] && nums[mid] < nums[right]) {
                break;
            }
            if (nums[mid] > nums[right]) {
                left = mid;
            } else if (nums[mid] < nums[right] && nums[mid] < nums[right]) {
                right = mid;
            }
        }
        return nums[left];
    }
};
