class Solution {
public:
    bool CanBeFormed(string &s, string &t) {
        int i_s = 0, i_t = 0;
        while (i_s < (int)s.size() && i_t < (int)t.size()) {
            if (s[i_s] == t[i_t]) {
                i_s++;
                i_t++;
            } else {
                i_s++;
            }
        }
        return i_t == (int)t.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
        int len = 0, pos = -1;
        for (int i = 0; i < (int)d.size(); i++) {
            if (CanBeFormed(s, d[i])) {
                if ((int)d[i].size() > len) {
                    len = (int)d[i].size();
                    pos = i;
                }
            }
        }
        return (pos == -1) ? "" : d[pos];
    }
};
