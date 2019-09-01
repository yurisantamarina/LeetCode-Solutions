class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> acc(s.size(), vector<int>(26, 0));
        for (int i = 0; i < s.size(); i++) {
            acc[i][s[i] - 'a'] = 1;
            for (int j = 0; i > 0 && j < 26; j++) {
                acc[i][j] += acc[i - 1][j];
            }
        }
        
        vector<bool> ans;
        for (vector<int>& q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int imp = 0;
            for (int i = 0; i < 26; i++) {
                int sum = acc[r][i] - (l > 0 ? acc[l - 1][i] : 0);
                imp += (sum & 1);
            }
            ans.push_back((imp / 2) <= k);
        }
        return ans;
    }
};
