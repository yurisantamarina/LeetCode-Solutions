
class Solution {
public:
    void dfs(int person, int N, vector<vector<int>>& M, vector<bool>& seen) {
        seen[person] = true;
        for (int i = 0; i < N; i++) {
            if (M[person][i] == 1 && !seen[i]) {
                dfs(i, N, M, seen);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int N = (int)M.size();
        vector<bool> seen(N, false);
        int answer = 0;
        for (int i = 0; i < N; i++) {
            if (!seen[i]) {
                dfs(i, N, M, seen);
                answer++;
            }
        }
        return answer;
    }
};
