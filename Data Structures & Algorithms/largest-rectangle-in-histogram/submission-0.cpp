class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = static_cast<int>(heights.size());
        vector<int> previous_min(n), following_min(n);
        stack<pair<int,int>> pse, nse;
        pse.emplace(-1, -1); nse.emplace(-1, n);
        for (int i = 0, j = n-1; i < n; i++, j--) {
            while (!pse.empty() && pse.top().first >= heights[i]) {
                pse.pop();
            }
            previous_min[i] = pse.top().second + 1;
            pse.emplace(heights[i], i);
            while (!nse.empty() && nse.top().first >= heights[j]) {
                nse.pop();
            }
            following_min[j] = nse.top().second - 1;
            nse.emplace(heights[j], j);
        }
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            max_area = max(max_area, heights[i] * (following_min[i] - previous_min[i] + 1));
        }
        return max_area;
    }
};
