class Solution {
public:
    const int INF = 100000000;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int height = (int) matrix.size();
        int width = (int) matrix[0].size();
        vector<vector<int> > prefix(height, vector<int>(width));
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                prefix[i][j] = matrix[i][j] == 1 ? INF : 0;
                if (i > 0) prefix[i][j] = min(prefix[i][j], prefix[i - 1][j] + 1);
                if (j > 0) prefix[i][j] = min(prefix[i][j], prefix[i][j - 1] + 1);
            }
        }
        
        for (int i = height - 1; i >= 0; i--) {
            for (int j = width - 1; j >= 0; j--) {
                if (i + 1 < height) prefix[i][j] = min(prefix[i][j], prefix[i + 1][j] + 1);
                if (j + 1 < width) prefix[i][j] = min(prefix[i][j], prefix[i][j + 1] + 1);
            }
        }
        
        return prefix;
    }
};
