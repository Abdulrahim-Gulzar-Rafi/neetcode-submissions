class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) {
            return false;
        }
        const int N = nums.size();
        unordered_set<int> st;
        int i = 0;
        for (i = 0; i < k; i++) {
            if (st.count(nums[i])) {
                return true;
            }
            st.insert(nums[i]);
        }
        while (i < N) {
            if (st.count(nums[i])) {
                return true;
            }
            st.erase(nums[i-k]);
            st.insert(nums[i]);
            i++;
        }
        return false;
    }
};