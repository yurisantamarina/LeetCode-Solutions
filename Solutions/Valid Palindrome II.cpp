class Solution {
public:
    bool IsPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int l = 0, r = int{s.size()} - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return IsPalindrome(s, l, r - 1) || IsPalindrome(s, l + 1, r);
            }
        }
        return true;
    }
};
