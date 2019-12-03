class Solution {
public:
    int dp[101][101][2][2];
    int n;
    int H = 0;
    int V = 1;
    int solve(int x, int y, int dir, bool rot, vector<vector<int>>& grid) {
        // printf("n = %d x = %d y = %d dir = %c rot = %s\n", n, x, y, dir == H ? 'H' : 'V', rot ? "true" : "false");
        if (x == n - 1 && y == n - 1) {
            return dir == H ? 0 : 1000000;
        }
        if (dp[x][y][dir][rot] != -1) return dp[x][y][dir][rot];
       
        int ans = 1000000;
        if (dir == H) {
            if (y + 1 < n && grid[x][y + 1] == 0) {
                ans = min(ans, 1 + solve(x, y + 1, H, false, grid));
            }
            if (x + 1 < n && y - 1 >= 0 && grid[x + 1][y] == 0 && grid[x + 1][y - 1] == 0) {
                ans = min(ans, 1 + solve(x + 1, y, H, false, grid));
            }
            if (!rot) {
                if (x + 1 < n && y - 1 >= 0 && grid[x + 1][y - 1] == 0 && grid[x + 1][y] == 0) {
                    ans = min(ans, 1 + solve(x + 1, y - 1, V, true, grid));
                }
            }
        } else {
            if (x + 1 < n && grid[x + 1][y] == 0) {
                ans = min(ans, 1 + solve(x + 1, y, V, false, grid));
            }
            if (y + 1 < n && x - 1 >= 0 && grid[x][y + 1] == 0 && grid[x - 1][y + 1] == 0) {
                ans = min(ans, 1 + solve(x, y + 1, V, false, grid));
            }
            if (!rot) {
                if (x - 1 >= 0 && y + 1 < n && grid[x - 1][y + 1] == 0 && grid[x][y + 1] == 0) {
                    ans = min(ans, 1 + solve(x - 1, y + 1, H, true, grid));
                }
            }
        }
        
        
        return dp[x][y][dir][rot] = ans;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof dp);
        int ans = solve(0, 1, H, false, grid);
        if (ans >= 1000000) ans = -1;
        return ans; 
    }
};
