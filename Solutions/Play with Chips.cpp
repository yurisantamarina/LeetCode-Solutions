class Solution {
public:
    long long calc(int final_pos, const vector<int>& chips) {
        long long ans = 0;
        for (int pos : chips) {
            long long dif = abs(final_pos - pos);
            if (dif & 1) {
                ans++;
            }
        }
        return ans;
    }
    
    int minCostToMoveChips(vector<int>& chips) {
        long long ans = 100000000000000LL;
        for (int final_pos : chips) {
            ans = min(ans, calc(final_pos, chips));
        }
        return ans;
    }
};
