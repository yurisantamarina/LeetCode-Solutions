class Solution {
public:
    // 1 2 3 5 8
    int climbStairs(int n) {
        int a = 1;
        int b = 2;
        if (n == 1) {
            return a;
        } else if (n == 2) {
            return b;
        } else {
            for (int i = 0; i < n - 2; i++) {
                int c = a + b;
                a = b;
                b = c;
            }
            return b;
        }
    }
};
