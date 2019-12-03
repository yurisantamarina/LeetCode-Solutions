class Solution {
public:
    bool ok(int len, vector<int>& v, int mx) {
        int l = 0;
        int r = len - 1;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += v[i];
        }
        if (sum <= mx) {
            return true;
        }
        while (r < v.size()) {
            sum -= v[l];
            l++;
            r++;
            if (r == v.size()) {
                break;
            }
            sum += v[r];
            if (sum <= mx) {
                return true;
            }
        }
        return false;
    }
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> v(s.size());
        for (int i = 0; i < s.size(); i++) {
            v[i] = abs(s[i] - t[i]);
        }
        int r = 0;
        int answer = 0;
        int lo = 0, hi = v.size(), mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (ok(mid, v, maxCost)) {
                lo = mid + 1;
                answer = mid;
            } else {
                hi = mid - 1;
            }
        }
        return answer;
    }
};
