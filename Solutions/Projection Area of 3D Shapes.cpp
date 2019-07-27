class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = int{grid.size()};
        
        int area = 0;
        for (int i = 0; i < n; i++) {
            int maximum_row = 0;
            int maximum_column = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    area++;
                }
                maximum_row = max(maximum_row, grid[i][j]);
                maximum_column = max(maximum_column, grid[j][i]);
            }
            area += maximum_row + maximum_column;
        }
        
        
        return area;
    }
};
