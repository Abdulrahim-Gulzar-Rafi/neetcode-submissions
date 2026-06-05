class Solution {
public:
    int maxArea(vector<int>& heights) {
        // at, height
        stack<pair<int,int>> tallest_bars;
        const int N = static_cast<int>(heights.size());
        int max_water = 0;
        for (int i = 0; i < N; i++) {
            if (tallest_bars.empty()) {
                tallest_bars.emplace(i, heights[i]);
            } else {
                // calculate the area
                // int width = i - tallest_bar.first;
                stack<pair<int,int>> swap;
                while (!tallest_bars.empty()) {
                    swap.emplace(tallest_bars.top());
                    const int width = i - tallest_bars.top().first;
                    const int height = min(tallest_bars.top().second, heights[i]);
                    const int area = width * height;
                    tallest_bars.pop();
                    if (area > max_water) {
                        max_water = area;
                    }
                }
                while (!swap.empty()) {
                    tallest_bars.emplace(swap.top());
                    swap.pop();
                }
                if (heights[i] > tallest_bars.top().second) {
                    tallest_bars.emplace(i, heights[i]);
                }
            }
        }
        return max_water;
    }
};
