class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = static_cast<int>(nums.size());
        if (k == n) {
            return {*max_element(nums.begin(), nums.end())};
        }
        multiset<int> st;
        int i = 0;
        for (i = 0; i < k; i++) {
            st.insert(nums[i]);
        }
        vector<int> answer;
        for (; i < n; i++) {
            int max_val = *st.rbegin();
            answer.push_back(max_val);
            auto it = st.find(nums[i - k]);
            if (it != st.end()) {
                st.erase(it);
            }
            st.insert(nums[i]);
        }
        int max_val = *st.rbegin();
        answer.push_back(max_val);
        return answer;
    }
};
