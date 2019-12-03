class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while (n > 0) {
            int m = n % 26;
            m--;
            if (m == -1) {
                n--;
                m = 25;
            }
            s += char(m + 'A');
            n /= 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
