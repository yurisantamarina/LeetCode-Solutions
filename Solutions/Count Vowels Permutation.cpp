class Solution {
public:
    int dp[20010][6];
    string s = "aeiou";
    int v[300];
    int mod = 1000000007;
    int solve(int pos, char lst, int n) {
        if (pos == n) {
            return 1;
        }
        if (dp[pos][v[lst]] != -1) return dp[pos][v[lst]];
        int ans = 0;
        if (lst == 'a') {
            ans = (ans + solve(pos + 1, 'e', n)) % mod;
        } else if (lst == 'e') {
            ans = (ans + solve(pos + 1, 'a', n)) % mod;
            ans = (ans + solve(pos + 1, 'i', n)) % mod;
        } else if (lst == 'i') {
            ans = (ans + solve(pos + 1, 'a', n)) % mod;
            ans = (ans + solve(pos + 1, 'e', n)) % mod;
            ans = (ans + solve(pos + 1, 'o', n)) % mod;
            ans = (ans + solve(pos + 1, 'u', n)) % mod;
        } else if (lst == 'o') {
            ans = (ans + solve(pos + 1, 'i', n)) % mod;
            ans = (ans + solve(pos + 1, 'u', n)) % mod;
        } else { // u
            ans = (ans + solve(pos + 1, 'a', n)) % mod;
        }
        return dp[pos][v[lst]] = ans;
    }
    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof dp);
        memset(v, -1, sizeof v);
        for (int i = 0; i < 5; i++) {
            v[s[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans = (ans + solve(1, s[i], n)) % mod;
        }
        return ans;
    }
};
