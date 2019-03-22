
class Solution {
public:
    // 299
    // 442 -> 399
    // 472 -> 469
    bool monotone(string &num){
        for (int i = 1; i < (int)num.size(); i++) {
            if (num[i - 1] > num[i]) return false;
        }
        return true;
    }
    
    int to_int(string &num) {
        int number = 0;
        for (char c : num) {
            number *= 10;
            number += (c - '0');
        }
        return number;
    }
    
    string decrease(string &num, int len_pref){
        string prefix = num.substr(0, len_pref);
        if (num[len_pref] == '0' || !monotone(prefix)) return "10";
        prefix += num[len_pref] - 1;
        for (int i = len_pref + 1; i < (int)num.size(); i++) {
            prefix += '9';
        }
        return prefix;
    }
    
    int monotoneIncreasingDigits(int N) {
        string num = to_string(N);
        if (monotone(num)) {
            return to_int(num);
        }       
        
        int answer = 0;
        string changed = "";
        for (int i = 0; i < (int)num.size(); i++) {
            changed = decrease(num, i);
            if (i > 0 && num[i - 1] > num[i]) break;
            if (monotone(changed)) {
                answer = to_int(changed);
            }
        }
        return answer;
    }
};
