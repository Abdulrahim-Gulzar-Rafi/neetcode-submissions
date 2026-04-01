class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = static_cast<int>(prices.size());
        int diff = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (i+1 < n && prices[i] <= prices[i+1]) {
                i++;
            }
            diff += (prices[i] - prices[j]);
        }
        return diff;
    }
};