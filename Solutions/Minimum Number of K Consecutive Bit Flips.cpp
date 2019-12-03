class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        vector<int> sum(int{A.size()} + 1, 0);
        int added = 0, flips = 0;
        for (int i = 0; i < int{A.size()}; i++) {
            added += sum[i];
            int cur = (A[i] + added % 2) % 2;
            if (i + K - 1 < int{A.size()}) {
                if (cur == 0) {
                    flips++;
                    sum[i]++;
                    sum[i + K]--;
                    added++;
                }
            } else {
                if (cur == 0) {
                    return -1;
                }
            }
        }
        return flips;
    }
};
