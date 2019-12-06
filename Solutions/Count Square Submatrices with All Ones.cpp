class Solution {
public:
    
    void BuildAccumulateSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
                if (j > 0) {
                    matrix[i][j] += matrix[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    matrix[i][j] -= matrix[i - 1][j - 1];
                }
            }
        }
    }
    
    bool Inside(int i, int j, int n, int m) {
        return i < n && j < m;
    }
    
    int GetSumSq(int a, int b, int len, const vector<vector<int>>& matrix) {
        int c = a + len - 1;
        int d = b + len - 1;
        int sum1 = matrix[c][d];
        int sum2 = (a > 0 && b > 0) ? matrix[a - 1][b - 1] : 0;
        int sum3 = (b > 0) ? matrix[c][b - 1] : 0;
        int sum4 = (a > 0) ? matrix[a - 1][d] : 0;
        return sum1 - sum3 - sum4 + sum2;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        BuildAccumulateSum(matrix);
        int n = matrix.size();
        int m = matrix[0].size();
        
        int good_sqs = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int len = 1; Inside(i + len - 1, j + len - 1, n, m); ++len) {
                    if (GetSumSq(i, j, len, matrix) == len * len) {
                        ++good_sqs;
                    }
                }
            }
        }
        return good_sqs;
    }
};
