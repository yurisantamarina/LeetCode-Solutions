class Solution {
public:
    bool colinear(vector<int>& a, vector<int>& b, vector<int>& c) {
        int ux = b[0] - a[0];
        int uy = b[1] - a[1];
        int vx = c[0] - a[0];
        int vy = c[1] - a[1];
        return (ux * vy - uy * vx) == 0;
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        for (int i = 1; i < coordinates.size() - 1; i++) {
            if (!colinear(coordinates[0], coordinates[i], coordinates[i + 1])) {
                return false;
            }
        }
        return true;
    }
};
