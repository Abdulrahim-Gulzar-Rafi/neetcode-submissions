class NumMatrix {
    vector<vector<int>> prefix_sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        const int n = static_cast<int>(matrix.size()), m = static_cast<int>(matrix[0].size());
        prefix_sums = vector(n, vector(m, 0));
        for (int i = 0; i < n; i++) {
            const int previous_level = i-1;
            int current_1D_sum = 0;
            for (int j = 0; j < m; j++) {
                current_1D_sum += matrix[i][j];
                int prefix_sum = current_1D_sum;
                if (previous_level >= 0) {
                    prefix_sum += prefix_sums[previous_level][j];
                }
                prefix_sums[i][j] = prefix_sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        const pair to_remove_left = {row2, col1-1}, to_remove_above = {row1-1, col2};
        const pair to_add = {row1-1, col1-1};
        int total_bottom_extreme_prefix_sum = prefix_sums[row2][col2];
        if (to_remove_left.second >= 0) {
            total_bottom_extreme_prefix_sum -= prefix_sums[to_remove_left.first][to_remove_left.second];
        }
        if (to_remove_above.first >= 0) {
            total_bottom_extreme_prefix_sum -= prefix_sums[to_remove_above.first][to_remove_above.second];
        }
        if (to_add.first >= 0 && to_add.second >= 0) {
            total_bottom_extreme_prefix_sum += prefix_sums[to_add.first][to_add.second];
        }
        return total_bottom_extreme_prefix_sum;
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */