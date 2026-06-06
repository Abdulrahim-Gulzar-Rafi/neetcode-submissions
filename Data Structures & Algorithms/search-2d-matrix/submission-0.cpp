class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int N = static_cast<int>(matrix.size()), M = static_cast<int>(matrix[0].size());
        int left = 0, right = N-1;
        while (left <= right) {
            const int mid = (left + right) / 2;
            if (matrix[mid][0] > target) {
                right = mid - 1;
            } else if (matrix[mid][M-1] < target) {
                left = mid + 1;
            } else {
                return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
            }
        }
        return false;
    }
};
