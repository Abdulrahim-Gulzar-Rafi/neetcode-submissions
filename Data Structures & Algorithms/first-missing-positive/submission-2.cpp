class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int current = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 1) {
                int j = i;
                while (j-1 >= 0 && nums[j-1] > 0) {
                    swap(nums[j], nums[j-1]);
                    j--;
                }
            } else {
                if (nums[i] != current) {
                    while (nums[i]-1 < n) {
                        if (nums[i] == nums[nums[i] - 1]) {
                            break;
                        }
                        swap(nums[i], nums[nums[i]-1]);
                        if (nums[i] < 1) {
                            int j = i;
                            while (j-1 >= 0 && nums[j-1] > 0) {
                                swap(nums[j], nums[j-1]);
                                j--;
                            }
                            break;
                        }
                    }
                    if (nums[i] != current) {
                        continue;
                    }
                }
                current ++;
            }
        }
        return current;
    }
};