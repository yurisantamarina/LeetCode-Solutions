class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mapa;
        for (string& word : words) {
            int mask = 0;
            for (char& c : word) {
                mask |= (1 << (c - 'a'));
            }
            mapa[mask]++;
        }
        
        vector<int> ans;
        int at;
        for (string& s : puzzles) {
            int lim = (1 << 6);
            at = 0;
            for (int i = 0; i < lim; i++) {
                int mask = (1 << (s[0] - 'a'));
                for (int bit = 0; bit < 6; bit++) {
                    if (i & (1 << bit)) {
                        mask |= (1 << (s[bit + 1] - 'a'));
                    }
                }
                at += mapa[mask];
            }
            ans.push_back(at);
        }
        return ans;
    }
};
