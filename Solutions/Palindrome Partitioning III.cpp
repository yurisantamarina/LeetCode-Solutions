class Solution {
public:
    int GetCost(int i, int j, const string& s) {
        int cost = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                cost++;
            }
            i++;
            j--;
        }
        return cost;
    }
    vector<vector<int>> PreprocessCosts(const string& s) {
        int n = s.size();
        vector<vector<int>> cost(s.size(), vector<int>(s.size(), 0));
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cost[i][j] = GetCost(i, j, s);
            }
        }
        return cost;
    }
    
    int palindromePartition(string s, int k) {
        s = "#" + s;
        vector<vector<int>> dp(s.size(), vector<int>(k + 1, 0));
        
        vector<vector<int>> cost = PreprocessCosts(s);
        
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            dp[i][1] = cost[1][i];
        }
        
        for (int K = 2; K <= k; ++K) {
            for (int i = K; i < n; ++i) {
                dp[i][K] = INT_MAX / 2;
                for (int j = 1; j <= i; ++j) {
                    dp[i][K] = min(dp[i][K], dp[j - 1][K - 1] + cost[j][i]);
                }
            }
        }
        return dp[n - 1][k];
    }
};
