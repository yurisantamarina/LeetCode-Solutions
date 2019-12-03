class Solution {
public:
    const vector<int> dx{1, 0, -1, 0};
    const vector<int> dy{0, 1, 0, -1};
    bool Inside(int x, int y, int N) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
    bool CanReachDfs(int x, int y, const vector<vector<int>>& grid, vector<vector<bool>>& seen, int elevation, int N) {
        if (x == N - 1 && y == N - 1) {
            return true;
        }
        seen[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (Inside(new_x, new_y, N) && !seen[new_x][new_y] && grid[new_x][new_y] <= elevation && CanReachDfs(new_x, new_y, grid, seen, elevation, N)) {
                return true;
            }
        }
        return false;
    }
    bool CanReach(const vector<vector<int>>& grid, int elevation, int N) {
        vector<vector<bool>> seen(N, vector<bool>(N, false));
        return CanReachDfs(0, 0, grid, seen, elevation, N);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int N = int{grid.size()};
        int lo = grid[0][0], hi = N * N - 1, mid, min_time = N * N - 1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (CanReach(grid, mid, N)) {
                min_time = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return min_time;
    }
};
