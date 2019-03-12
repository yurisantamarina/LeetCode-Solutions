class Solution {
public:
    int countDp(int i, int j, string &s, string &t, vector<vector<int> >& dp){
        if(j == (int)t.size()) return 1;
        if(i == (int)s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        
        if(s[i] == t[j]){
            ans = countDp(i + 1, j + 1, s, t, dp) + countDp(i + 1, j, s, t, dp);
        }else{
            ans = countDp(i + 1, j, s, t, dp);
        }
        
        return dp[i][j] = ans;
    }
        
    int numDistinct(string s, string t) {
        vector<vector<int> > dp;
        dp.resize((int)s.size());
        for(int i = 0; i < (int)s.size(); i++){
            dp[i].resize((int)t.size(), -1);
        }
        return countDp(0, 0, s, t, dp);
    }
};
