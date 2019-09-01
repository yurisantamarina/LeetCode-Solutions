class Solution {
public:
    int bestRotation(vector<int>& A) {
        vector<int> acc(A.size() + 1, 0);
        int n = A.size();
        for (int i = 0; i < A.size(); i++) {
            if (A[i] <= i) {
                int l = 0;
                int r = i - A[i];
                if (l <= r) {
                    acc[l]++;
                    acc[r + 1]--;
                }
                l = i + 1;
                r = n - 1;
                if (l <= r) {
                    acc[l]++;
                    acc[r + 1]--;
                }
            } else {
                int l = i + 1;
                int r = i + (n - A[i]);
                if (l <= r) {
                    acc[l]++;
                    acc[r + 1]--;
                }
            }
        }
        int mx_rot = 0;
        int active = 0;
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            active += acc[i];
            if (active > ans) {
                ans = active;
                mx_rot = i;
            }
        }
        return mx_rot;
    }
};
