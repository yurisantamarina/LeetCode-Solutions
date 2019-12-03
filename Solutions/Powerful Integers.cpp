class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> answer;
        int xx = 1;
        unordered_set<int> seen;
        for (int i = 0; i <= bound; i++) {
            if (xx > bound) break;
            int yy = 1;
            for (int j = 0; j <= bound; j++) {
                if (xx + yy > bound) break;
                if (!seen.count(xx + yy)) {
                    answer.push_back(xx + yy);
                    seen.insert(xx + yy);
                }
                yy *= y;
            }
            xx *= x;
        }
        return answer;
    }
};
