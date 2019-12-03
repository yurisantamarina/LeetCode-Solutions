class Solution {
public:
    unordered_set<int> vis[16];
    int ans = 0, n, m;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    bool can(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] > 0 && !vis[x].count(y);
    }
    
    void dfs(int x, int y, vector<vector<int>>& grid, int cost) {
        ans = max(ans, cost);
        vis[x].insert(y);
        for (int i = 0; i < 4; i++) {
            if (can(x + dx[i], y + dy[i], grid)) {
                dfs(x + dx[i], y + dy[i], grid, cost + grid[x + dx[i]][y + dy[i]]);
            }
        }
        vis[x].erase(y);
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    dfs(i, j, grid, grid[i][j]);
                }
            }
        }
        return ans;
    }
};
