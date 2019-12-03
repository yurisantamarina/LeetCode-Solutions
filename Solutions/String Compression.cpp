class Solution {
public:
    
    void InsertCounter(vector<char>& chars, int& len, int counter) {
        if (counter == 1) {
            return;
        }
        string s = "";
        while (counter > 0) {
            s += char(counter % 10 + '0');
            counter /= 10;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            chars[len++] = s[i];
        }
    }
    
    int compress(vector<char>& chars) {
        chars.push_back(34);
        int counter = 1;
        int len = 0;
        for (int i = 1; i < int{chars.size()}; i++) {
            if (chars[i] != chars[i - 1]) {
                chars[len++] = chars[i - 1];
                InsertCounter(chars, len, counter);
                counter = 1;
            } else {
                counter++;
            }
        }
        return len;
    }
};
