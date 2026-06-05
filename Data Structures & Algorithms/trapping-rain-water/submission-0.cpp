class Solution {
public:
    int trap(vector<int>& height) {
        const int N = static_cast<int>(height.size());
        int j = N-1;
        vector nge(N,0);
        stack<int> nge_stack;
        for (int i = N-1; i >= 0; i--) {
            if (nge_stack.empty()) {
                nge_stack.emplace(height[i]);
                continue;
            }
            nge[i] = nge_stack.top();
            if (height[i] > nge_stack.top()) {
                nge_stack.emplace(height[i]);
            }
        }
        int pge = 0;
        int total_water = 0;
        for (int i = 0; i < N; i++) {
            // calculate water
            if (height[i] < pge && height[i] < nge[i]) {
                total_water += (min(pge, nge[i]) - height[i]);
            }

            // then set pge
            if (height[i] > pge) {
                pge = height[i];
            }
        }
        return total_water;

    }
};
