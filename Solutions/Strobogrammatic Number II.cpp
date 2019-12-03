class Solution {
public:
    unordered_map<char, char> equivalent{{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
    
    string BuildSecondHalf(string& cur_strobogrammatic, int n) {
        string strobogrammatic = cur_strobogrammatic;
        int start = n & 1 ? strobogrammatic.size() - 2 : strobogrammatic.size() - 1;
        for (int i = start; i >= 0; i--) {
            strobogrammatic.push_back(equivalent[cur_strobogrammatic[i]]);
        }
        return strobogrammatic;
    }
    
    void FindAllStrobogrammatic(int index, int half_len_up, int n, vector<string>& all_strobogrammatic, string& cur_strobogrammatic) {
        if (index == half_len_up) {
            string strobogrammatic = BuildSecondHalf(cur_strobogrammatic, n);
            all_strobogrammatic.push_back(strobogrammatic);
            return;
        }
        for (auto i : equivalent) {
            if (i.first == '0' && index == 0) {
                continue;
            }
            if ((n & 1) && index == half_len_up - 1 && (i.first == '6' || i.first == '9')) {
                continue;
            }
            cur_strobogrammatic += i.first;
            FindAllStrobogrammatic(index + 1, half_len_up, n, all_strobogrammatic, cur_strobogrammatic);
            cur_strobogrammatic.pop_back();
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        if (n == 1) {
            return {"0", "1", "8"};
        }
        int half_len_up = ((n / 2) + (n & 1));
        vector<string> all_strobogrammatic;
        string cur_strobogrammatic = "";
        FindAllStrobogrammatic(0, half_len_up, n, all_strobogrammatic, cur_strobogrammatic);
        return all_strobogrammatic;
    }
};
