class Solution {
public:
    vector<string> commonChars(vector<string>& A) {   
        vector<int> minimum_frequency(26, INT_MAX);
        vector<int> curr_frequency(26, 0);
        
        for (int i = 0; i < int{A.size()}; i++) {
            for (const char& letter : A[i]) {
                curr_frequency[letter - 'a']++;
            }
            
            for (int c = 0; c < 26; c++) {
                minimum_frequency[c] = min(minimum_frequency[c], curr_frequency[c]);
                curr_frequency[c] = 0;
            }
        }
        
        vector<string> common;
        for (int c = 0; c < 26; c++) {
            if (minimum_frequency[c] != INT_MAX) {
                while (minimum_frequency[c] > 0) {
                    common.push_back(string(1, char(c + 'a')));
                    minimum_frequency[c]--;
                }
            }
        }
        
        return common;
    }
};
