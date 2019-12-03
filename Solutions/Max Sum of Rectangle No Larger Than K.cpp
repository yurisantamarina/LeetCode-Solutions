class Solution {
public:
    
    vector<vector<int>> BuildPrefixSumRows(const vector<vector<int>>& matrix, int num_rows, int num_cols) {
        vector<vector<int>> prefix_sum_rows(num_rows, vector<int>(num_cols, 0));
        for (int row = 0; row < num_rows; row++) {
            for (int col = 0; col < num_cols; col++) {
                prefix_sum_rows[row][col] = matrix[row][col];
                if (col > 0) {
                    prefix_sum_rows[row][col] += prefix_sum_rows[row][col - 1];
                }
            }
        }
        return prefix_sum_rows;
    }
    
    int GetRowSum(int row, int col_l, int col_r, const vector<int>& prefix_sum_row) {
        return prefix_sum_row[col_r] - (col_l > 0 ? prefix_sum_row[col_l - 1] : 0);
    }
    
    int GetMaxRectangleFixed(int col_l, int col_r, int num_rows, const vector<vector<int>>& prefix_sum_rows, int k) {
        set<int> prefix_sum_col;
        prefix_sum_col.insert(0);
        int cur_prefix_sum = 0;
        int max_rectangle_sum = -INT_MAX;
        for (int row = 0; row < num_rows; row++) {
            cur_prefix_sum += GetRowSum(row, col_l, col_r, prefix_sum_rows[row]);
            auto next_greater = prefix_sum_col.lower_bound(cur_prefix_sum - k);
            if (next_greater != prefix_sum_col.end()) {
               max_rectangle_sum = max(max_rectangle_sum, cur_prefix_sum - *next_greater);
            }
            prefix_sum_col.insert(cur_prefix_sum);
            
        }
        return max_rectangle_sum;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();
        vector<vector<int>> prefix_sum_rows = BuildPrefixSumRows(matrix, num_rows, num_cols);
        int max_sum = -INT_MAX;
        for (int col_l = 0; col_l < num_cols; col_l++) {
            for (int col_r = col_l; col_r < num_cols; col_r++) {
                max_sum = max(max_sum, GetMaxRectangleFixed(col_l, col_r, num_rows, prefix_sum_rows, k));
            }
        }
        return max_sum;
    }
};
