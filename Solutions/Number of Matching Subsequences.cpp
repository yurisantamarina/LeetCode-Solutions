class Solution {
public:
    int FindNextMatchPosition(char c, const vector<int>& pos, int last_match_pos) {
        int ub_result = upper_bound(pos.begin(), pos.end(), last_match_pos) - pos.begin();
        if (ub_result == pos.size()) {
            return -1;
        }
        return pos[ub_result];
    }
    
    int IsSubsequence(const string& word, const string& S, const vector<vector<int>>& letter_pos) {
        if (word.size() > S.size()) {
            return 0;
        }
        int last_match_pos = -1;
        for (char c : word) {
            int next_match_pos = FindNextMatchPosition(c, letter_pos[c - 'a'], last_match_pos);
            if (next_match_pos == -1) {
                return 0;
            }
            last_match_pos = next_match_pos;
        }
        return 1;
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> letter_pos(26, vector<int>());
        for (int pos = 0; pos < S.size(); pos++) {
            int letter = S[pos] - 'a';
            letter_pos[letter].push_back(pos);
        }
        int num_subseq = 0;
        for (const string& word : words) {
            num_subseq += IsSubsequence(word, S, letter_pos);
        }
        return num_subseq;
    }
};
