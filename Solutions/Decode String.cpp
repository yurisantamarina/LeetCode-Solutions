class Solution {
public:
    string decodeString(string s) {
        vector<int> pot10{1, 10, 100, 1000, 10000};
        reverse(s.begin(), s.end());
        stack<char> p;
        string cur;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                s[i] = ']';
            } else if (s[i] == ']') {
                s[i] = '[';
            }
            char c = s[i];
            if (c == ']') {
                cur = "";
                while (p.top() != '[') {
                    cur += p.top();
                    p.pop();
                }
                p.pop();
                i++;
                int len_num = 0, num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num += (s[i] - '0') * pot10[len_num++];
                    i++;
                }
                i--;
                while (num > 0) {
                    for (int i = cur.size() - 1; i >= 0; i--) {
                        p.push(cur[i]);
                    }
                    num--;
                }
            } else {
                p.push(c);
            }
        }
        cur = "";
        while (!p.empty()) {
            cur += p.top();
            p.pop();
        }
        return cur;
    }
};
