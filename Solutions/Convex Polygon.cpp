class Solution {
public:
    vector<int> GetVector(int i, int j, const vector<vector<int>>& points) {
        return {points[j][0] - points[i][0], points[j][1] - points[i][1]};
    }
    int CrossProduct(const vector<int>& pt_a, const vector<int>& pt_b) {
        return pt_a[0] * pt_b[1] - pt_a[1] * pt_b[0];
    }
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        bool has_positive = false;
        bool has_negative = false;
        for (int i = 0; i < n; i++) {
            vector<int> nxt = GetVector(i, (i + 1) % n, points);
            vector<int> nxt_nxt = GetVector(i, (i + 2) % n, points);
            int cross = CrossProduct(nxt, nxt_nxt);
            if (cross > 0) {
                if (has_negative) {
                    return false;
                }
                has_positive = true;
            }
            if (cross < 0) {
                if (has_positive) {
                    return false;
                }
                has_negative = true;
            }
        }
        return true;
    }
};
