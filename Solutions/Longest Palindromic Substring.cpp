class Solution {
public:
    string longestPalindrome(string s) {
        int n = int{s.size()};
        if (n == 0) {
            return "";
        }
        vector<vector<bool> > dp(3, vector<bool>(n + 1));
        int mx = 1, beg = 0;
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                if (len == 1) {
                    dp[len % 3][l] = true;
                } else if (len == 2) {
                    dp[len % 3][l] = (s[l] == s[r]);
                } else {
                    dp[len % 3][l] = (s[l] == s[r]) && dp[(len - 2) % 3][l + 1];
                }
                if (dp[len % 3][l]) {
                    mx = len;
                    beg = l;
                }
            }
        }
        return s.substr(beg, mx);
    }
    
};
