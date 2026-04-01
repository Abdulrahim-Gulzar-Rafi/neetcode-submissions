class NumMatrix {
    vector<vector<int>> colsums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        colsums = matrix;
        for (int j = 0; j < matrix[0].size(); j++) {
            int sum = 0;
            for (int i = 0; i < matrix.size(); i++) {
                sum += matrix[i][j];
                colsums[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = col1; i <= col2; i++) {
            if (row1-1 >= 0) {
                sum += colsums[row2][i] - colsums[row1-1][i];
            } else {
                sum += colsums[row2][i];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */