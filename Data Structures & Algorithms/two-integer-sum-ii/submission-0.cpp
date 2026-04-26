class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        const int n = static_cast<int>(numbers.size());
        while (i < n) {
            const int required = target - numbers[i];
            auto it = lower_bound(numbers.begin() + i + 1, numbers.end(), required);
            if (it != numbers.end() && *it == required) {
                return {i+1, static_cast<int>(it - numbers.begin()) + 1};
            }
            while (i+1 < n && numbers[i] == numbers[i+1]) {
                i++;
            }
            i++;
        }
        return {0, 0};
    }
};
