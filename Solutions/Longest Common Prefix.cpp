class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (int{strs.size()} == 0) {
            return "";
        }
        int min_len = int{strs[0].size()};
        for (int i = 1; i < int{strs.size()}; i++) {
            min_len = min(min_len, int{strs[0].size()});
        }
        string longest_prefix = "";
        for (int i = 0; i < min_len; i++) {
            bool error = false;
            for (int j = 1; j < int{strs.size()}; j++) {
                if (strs[j][i] != strs[j - 1][i]) {
                    error = true;
                    break;
                }
            }
            if (error) {
                break;
            }
            longest_prefix += strs[0][i];
        }
        
        return longest_prefix;
    }
};
