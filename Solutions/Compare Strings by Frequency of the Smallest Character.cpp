class Solution {
public:
    int F(string& s) {
        vector<int> f(26, 0);
        for (char& c : s) {
            f[c - 'a']++;
        }
        for (int& i : f) {
            if (i != 0) {
                return i;
            }
        }
        return 0;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> a, b;
        for (string& s : queries) {
            a.push_back(F(s));
        }
        for (string& s : words) {
            b.push_back(F(s));
        }
        int idx = 0;
        vector<int> ans(a.size(), 0);
        for (int& i : a) {
            for (int& j : b) {
                ans[idx] += (i < j);
            }
            idx++;
        }
        return ans;
    }
};
