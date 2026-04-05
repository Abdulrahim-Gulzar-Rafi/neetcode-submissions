class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        deque<pair<int,int>> dq;
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++) {
            if (dq.empty()) {
                dq.push_back({nums[i], 1});
                continue;
            }
            if (dq.front().first == nums[i]) {
                dq.front().second ++;
            } else if (dq.back().first == nums[i]) {
                dq.back().second ++;
                if (dq.size() == 2 && dq.back().second > dq.front().second) {
                    swap(dq.back(), dq.front());
                }
            } else {
                if (dq.size() < 2) {
                    dq.emplace_back(nums[i], 1);
                } else {
                    dq.back().second --;
                    if (dq.back().second == 0) {
                        dq.pop_back();
                    }
                }
            }
        }
        dq.front().second = 0;
        dq.back().second = 0;
        bool size_2 = dq.size() == 2;
        for (int i = 0; i < n; i++) {
            if (nums[i] == dq.front().first) {
                dq.front().second ++;
            }
            if (size_2 && nums[i] == dq.back().first) {
                dq.back().second ++;
            }
        }
        if (dq.back().second <= n / 3) {
            dq.pop_back();
        }
        if (dq.empty()) return {};
        if (dq.front().second <= n / 3) {
            dq.pop_front();
        }
        vector<int> ans;
        for (auto i: dq) {
            ans.push_back(i.first);
        }
        return ans;

    }
};