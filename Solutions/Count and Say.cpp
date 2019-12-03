class Solution {
public:
    
    string GetNext(string& s) {
        s += '$';
        string next = "";
        int counter = 1;
        for (int i = 1; i < int{s.size()}; i++) {
            if (s[i] != s[i - 1]) {
                next += to_string(counter) + string(1, s[i - 1]);
                counter = 1;
            } else {
                counter++;
            }
        }
        return next;
    }
    
    string countAndSay(int n) {
        string cur = "1";
        while (n > 1) {
            cur = GetNext(cur);
            n--;
        }
        return cur;
    }
};
