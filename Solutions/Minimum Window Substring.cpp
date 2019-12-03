class Solution {
public:
    int MapLetter(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A';
        }
        return 26 + c - 'a';
    }
    string minWindow(string s, string t) {
        vector<int> frequency_t(52, 0);
        int distinct_letters_t = 0;
        
        for (char& c : t) {
            int letter = MapLetter(c);
            frequency_t[letter]++;
            if (frequency_t[letter] == 1) {
                distinct_letters_t++;
            }
        }
        int R = 0;
        vector<int> frequency_window(52, 0);
        int distinct_letters_from_t_window = 0;
        int L_ans = -1, R_ans = -1, ans = 1000000000;
        for (int L = 0; L < s.size(); L++) {
            while (R < s.size() && distinct_letters_from_t_window < distinct_letters_t) {
                int letter = MapLetter(s[R]);
                if (frequency_t[letter] > 0) {
                    frequency_window[letter]++;
                    if (frequency_window[letter] == frequency_t[letter]) {
                        distinct_letters_from_t_window++;
                    }
                }
                R++;
            }
            if (distinct_letters_from_t_window == distinct_letters_t) {
                if (R - L < ans) {
                    ans = R - L;
                    L_ans = L;
                    R_ans = R;
                }
            }
            int letter = MapLetter(s[L]);
            if (frequency_t[letter] > 0) {
                frequency_window[letter]--;
                if (frequency_window[letter] == frequency_t[letter] - 1) {
                    distinct_letters_from_t_window--;
                }
            }
        }
        
        if (L_ans < 0) {
            return "";
        }
        return s.substr(L_ans, ans);
    }
};
