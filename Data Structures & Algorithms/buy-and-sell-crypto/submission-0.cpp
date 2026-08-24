class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        const int N = static_cast<int>(prices.size());
        int max_profit_left = 0, max_profit_right = 0;
        for (int i = 0; i < N; ++i) {
            while (i+1 < N && prices[i] >= prices[i+1]) {
                ++i;
            }
            if (i > max_profit_left && i < max_profit_right && prices[i] > prices[max_profit_left]) {
                continue;
            }
            int limit = prices[i];
            int left = i, right = i+1;
            if (left == N-1) {
                break;
            }
            int maxSellingStock = limit;
            while (right < N && prices[right] > prices[left]) {
                maxSellingStock = max(maxSellingStock, prices[right]);
                ++right;
            }
            int profit = maxSellingStock - limit;
            if (profit > max_profit) {
                max_profit = profit;
                max_profit_left = left;
                max_profit_right = right;
            }
        }
        return max_profit;
    }
};
