class Solution {
public:
    void dfs(int left_k, int lst, int left_n, vector<int>& cur_comb, vector<vector<int>>& all_comb) {
        if (left_n < 0) {
            return;
        }
        if (left_k == 0) {
            if (left_n == 0) {
                all_comb.push_back(cur_comb);    
            }
            return;
        }
        for (int cur_elem = lst + 1; cur_elem < 10; cur_elem++) {
            cur_comb.push_back(cur_elem);
            dfs(left_k - 1, cur_elem, left_n - cur_elem, cur_comb, all_comb);
            cur_comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur_comb;
        vector<vector<int>> all_comb;
        dfs(k, 0, n, cur_comb, all_comb);
        return all_comb;
    }
};
