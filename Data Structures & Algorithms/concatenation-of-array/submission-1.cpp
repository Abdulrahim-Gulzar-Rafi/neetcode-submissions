class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        nums.resize(static_cast<int>(nums.size()) * 2);
        for (int i = 0; i < n; i++) {
            nums[n + i] = nums[i];
        }
        return nums;        
    }
};