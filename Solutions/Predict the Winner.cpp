class Solution {
public:
    bool PredictTheWinner(vector<int>& v) {
        int n = int{v.size()};
        vector<vector<int> > dp(3, vector<int>(n + 1));
        
        int tot = 0;
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (len == 1) {
                    tot += v[l];
                }
                if (len == 1) {
                    dp[len % 3][l] = v[l];
                } else if (len == 2) {
                    dp[len % 3][l] = max(v[l], v[r]);
                } else {
                    dp[len % 3][l] = max(v[l] + min(dp[(len - 2) % 3][l + 2], dp[(len - 2) % 3][l + 1]),
                                         v[r] + min(dp[(len - 2) % 3][l + 1], dp[(len - 2) % 3][l]));
                }
            } 
        }
        
        return dp[n % 3][0] >= (tot - dp[n % 3][0]);
    }
};
