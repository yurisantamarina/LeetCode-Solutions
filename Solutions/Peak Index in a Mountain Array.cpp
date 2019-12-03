class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0, hi = A.size() - 2, mid = 0, ans = 0;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (A[mid] < A[mid + 1]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};
