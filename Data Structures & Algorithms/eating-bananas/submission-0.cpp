class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        auto validateK = [piles, h](const int& k) -> int {
            int hours_used = 0;
            for (const int& i: piles) {
                hours_used += static_cast<int>(ceil(static_cast<double>(i) / k));
            }
            return hours_used == h ? 1 : hours_used > h ? 0 : 2;
        };

        int ans = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            int hours = 0;
            for (const int& i: piles) {
                hours += static_cast<int>(ceil(static_cast<double>(i) / mid));
            }
            if (hours <= h) {
                ans = min(mid, ans);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;

    }
};
