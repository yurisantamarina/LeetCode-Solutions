class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<vector<int>> min_swaps(A.size(), vector<int>(2, INT_MAX / 2));
        min_swaps[0][0] = 0;
        min_swaps[0][1] = 1;
        int ans = INT_MAX;
        for (int idx = 1; idx < A.size(); idx++) {
            int cur_a = A[idx];
            int cur_b = B[idx];
            for (int swapped = 0; swapped < 2; swapped++) {
                if (swapped) {
                    swap(cur_a, cur_b);
                }
                for (int prev_swapped = 0; prev_swapped < 2; prev_swapped++) {
                    int prev_a = A[idx - 1];
                    int prev_b = B[idx - 1];
                    if (prev_swapped) {
                        swap(prev_a, prev_b);
                    }
                    if (prev_a < cur_a && prev_b < cur_b) {
                        min_swaps[idx][swapped] = min(min_swaps[idx][swapped], min_swaps[idx - 1][prev_swapped] + swapped);
                    }
                }
                if (idx == A.size() - 1) {
                    ans = min(ans, min_swaps[idx][swapped]);
                }
            }
        }
        return ans;
    }
};
