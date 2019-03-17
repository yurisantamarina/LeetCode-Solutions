class Solution {
public:
    int uniqueLetterString(string S) {
        vector<int> pos[27];
        for(int i = 0; i < (int)S.size(); i++){
            pos[S[i] - 'A'].push_back(i);
        }
        
        int ans = 0, l, r;
        int MOD = 1000000007;
        for(int letter = 0; letter < 27; letter++){
            for(int i = 0; i < (int)pos[letter].size(); i++){
                l = pos[letter][i] - ((i == 0) ? 0 : pos[letter][i - 1] + 1) + 1;
                r = ((i + 1) == (int)pos[letter].size() ? (int)S.size() - 1 : pos[letter][i + 1] - 1) - pos[letter][i] + 1;
                ans = (ans + ((long long) l * r) % MOD) % MOD;
            }
        }
        return ans;
    }
};
