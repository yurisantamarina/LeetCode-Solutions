class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.size() == 1) {
            return arr[0];
        }
        vector<vector<int>> dp(arr.size(), vector<int>(2, 0));
        dp[0][1] = 0;
        dp[0][0] = arr[0];
        int ans = dp[0][0];
        for (int i = 1; i < arr.size(); i++) {
            dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
            dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
            ans = max({ans, dp[i][1], dp[i][0]});
        }
        return ans;
    }
};
