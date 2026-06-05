class Solution {
public:
    int maxArea(vector<int>& heights) {
        // at, height
        int N = static_cast<int>(heights.size());
        int left = 0, right = N-1;
        int max_water = 0;
        while (left <= right) {
            int area = (right - left) * min(heights[left], heights[right]);
            max_water = max(area, max_water);
            if (heights[left] < heights[right]) {
                left ++;
            } else {
                right --;
            }
        }
        return max_water;
    }
};
