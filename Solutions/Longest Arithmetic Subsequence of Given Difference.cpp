class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> dp;
        int cur;
        int ans = 0;
        for (int x : arr) {
            if (dp.count(x - difference)) {
                cur = dp[x - difference] + 1;
            } else {
                cur = 1;
            }
            cur = max(cur, dp[x]);
            dp[x] = cur;
            ans = max(ans, cur);
        }
        return ans;
    }
};
