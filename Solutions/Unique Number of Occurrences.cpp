class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> f;
        for (int x : arr) {
            f[x]++;
        }
        set<int> a;
        for (auto i : f) {
            if (a.count(i.second)) {
                return false;
            }
            a.insert(i.second);
        }
        return true;
    }
};
