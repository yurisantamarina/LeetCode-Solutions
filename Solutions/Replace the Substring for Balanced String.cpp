class Solution {
public:
    unordered_map<char, int> mapa{{'Q', 0}, {'W', 1}, {'E', 2}, {'R', 3}};
    int n, Q, W, E, R;
    vector<int> acc[4];
    
    
    bool balanced(int a, int b, int c, int d) {
        return a == (n / 2) && b == (n / 4) && c == (n / 4) && d == (n / 4);
    }
    
    int getSum(int letter, int l, int r) {
        if (l > r) {
            return 0;
        }
        return acc[letter][r] - (l > 0 ? acc[letter][l - 1] : 0);
    }
    
    bool ok(int len, string& s) {
        int l = 0, r = len - 1;
        int want = n / 4;
        int Q_, W_, E_, R_;
        while (r < n) {
            int qout = getSum(0, 0, l - 1) + getSum(0, r + 1, n - 1);
            int wout = getSum(1, 0, l - 1) + getSum(1, r + 1, n - 1);
            int eout = getSum(2, 0, l - 1) + getSum(2, r + 1, n - 1);
            int rout = getSum(3, 0, l - 1) + getSum(3, r + 1, n - 1);
            if (qout <= want && wout <= want && eout <= want && rout <= want) {
                return true;
            }
            l++;
            r++;
        }
        return false;
    }
    
    int balancedString(string s) {
        
        for (int i = 0; i < s.size(); i++) {
            int c = mapa[s[i]];
            for (int j = 0; j < 4; j++) {
                if (j == c) {
                    acc[j].push_back(1);
                } else {
                    acc[j].push_back(0);
                }
                if (i > 0) {
                    acc[j][i] += acc[j][i - 1];
                }
            }
        }
        Q = acc[0][s.size() - 1];
        W = acc[1][s.size() - 1];
        E = acc[2][s.size() - 1];
        R = acc[3][s.size() - 1];
        n = s.size();
        if (balanced(Q, W, E, R)) {
            return 0;
        }
        int lo = 0, hi = s.size(), mid;
        int ans = n;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (ok(mid, s)) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
