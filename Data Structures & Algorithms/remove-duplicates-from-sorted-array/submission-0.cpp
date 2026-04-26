class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int duplicates = 0;
        for (int i = 0; i < n; i++) {
            while (i+1 < n && nums[i+1] == nums[i]) {
                nums[i] = -101;
                duplicates ++;
                i++;
            }
        }
        int u = 0;
        for (int i = 0; i < n; i++) {
            while (u < n && nums[u] == -101) {
                u++;
            }
            if (u < n) {
                nums[i] = nums[u];
            }
            u++;
        }
        return n-duplicates;
    }
};