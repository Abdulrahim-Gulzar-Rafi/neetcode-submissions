class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left_prod = 1, right_prod = 1;
        int n = static_cast<int>(nums.size());
        vector<int> resultant(nums.begin(), nums.end());
        int j = n-1;
        for (int i = 0; i < n; i++) {
            if (i > j) {
                resultant[i] = left_prod * resultant[i];
                resultant[j] = right_prod * resultant[j];
            } else if (i == j) {
                resultant[i] = left_prod * right_prod;
            } else {
                resultant[i] = left_prod;
                resultant[j] = right_prod;
            }
            left_prod *= nums[i];
            right_prod *= nums[j];
            j--;
        }
        return resultant;
    }
};
