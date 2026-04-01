class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        nums.resize(n * 2);
        for (int i = n; i < nums.size(); i++) {
            nums[i] = nums[i-n];
        }
        return nums;
    }
};