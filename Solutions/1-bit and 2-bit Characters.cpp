class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = (int)bits.size() - 1;
        if (n == 0) return true;
        
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        dp[n - 1] = bits[n - 1] == 0;
        for (int i = n - 2; i >= 0; i--) {
            if (bits[i] == 0) {
                dp[i] = dp[i + 1];
            } else {
                dp[i] = dp[i + 2];
            }
        }
        
        return dp[0];
    }
};