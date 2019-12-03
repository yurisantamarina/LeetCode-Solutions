class Solution {
public:
    const vector<int> dx{1,0,-1,0};
    const vector<int> dy{0,1,0,-1};
    
    bool CanGo(const int x, const int y, const int visited_mask, const vector<vector<int>>& grid, const int n, const int m) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return false;
        }
        if (grid[x][y] == -1) {
            return false;
        }
        int vertex_1d = x * m + y;
        return !(visited_mask & (1 << vertex_1d));
    }
    
    int CountPaths(const int x, const int y, const int visited_mask, const vector<vector<int>>& grid, const int n, const int m, const int empty_cells, const int visited, vector<vector<int>>& dp) {
        if (grid[x][y] == 2) {
            return visited == empty_cells ? 1 : 0;
        }
        int cur_vertex_1d = x * m + y;
        if (dp[cur_vertex_1d][visited_mask] != -1) {
            return dp[cur_vertex_1d][visited_mask];
        }
        
        int num_paths = 0;
        for (int i = 0; i < 4; i++) {
            if (CanGo(x + dx[i], y + dy[i], visited_mask, grid, n, m)) {
                int vertex_1d = (x + dx[i]) * m + (y + dy[i]);
                num_paths += CountPaths(x + dx[i], y + dy[i], visited_mask | (1 << vertex_1d), grid, n, m, empty_cells, visited + 1, dp);
            }
        }
        return dp[cur_vertex_1d][visited_mask] = num_paths;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int empty_cells = 0;
        int n = grid.size();
        int m = grid[0].size();
        int start_x, start_y;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) {
                    empty_cells++;
                }
                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        vector<vector<int>> dp(n * m, vector<int>(1 << (n * m), -1));
        int initial_mask = 1 << (start_x * m + start_y);
        return CountPaths(start_x, start_y, initial_mask, grid, n, m, empty_cells, 1, dp);
    }
};
