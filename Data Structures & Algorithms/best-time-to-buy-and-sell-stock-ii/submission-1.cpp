class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        const int n = static_cast<int>(prices.size());
        for (int i = 0; i < n; i++) {
            int j = i;
            while (i+1 < n && prices[i+1] > prices[i]) {
                i++;
            }
            profit += (prices[i] - prices[j]);
        }
        return profit;
    }
};