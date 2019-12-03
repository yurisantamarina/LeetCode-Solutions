class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> p;
        for (char c : s) {
            if (p.empty()) {
                p.push({c, 1});
            } else {
                if (p.top().first == c) {
                    int x = p.top().second;
                    p.push({c, x + 1});
                } else {
                    p.push({c, 1});
                }
            }
            if (p.top().second == k) {
                int x = k;
                while (x > 0) {
                    p.pop();
                    x--;
                }
            }
        }
        s = "";
        while (!p.empty()) {
            s += p.top().first;
            p.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
