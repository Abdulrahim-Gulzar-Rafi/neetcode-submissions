class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = static_cast<int>(nums.size());
        int left = 0, right = n-1;
        while (left <= right) {
            if (nums[left] == val) {
                while (right >= 0 && nums[right] == val && right >= left) {
                    right --;
                }
                if (left > right || left > n || right < 0) {
                    break;
                }
                swap(nums[left], nums[right]);
            }
            left ++;
        }
        return left;
    }
};