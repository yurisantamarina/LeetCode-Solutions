class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0, can = 0, a = 0;
        for (int i = 0; i < (int)flowerbed.size(); i++) {
            if (flowerbed[i] == 1) {
                if (cnt == i) {
                    a = max(0, cnt - 1);
                } else {
                    a = max(0, cnt - 2);
                }
                can += (a / 2 + (a % 2 != 0 ? 1 : 0));
                cnt = 0;
            } else {
                cnt++;
            }
        }
        
        if (cnt == (int)flowerbed.size()) {
            a = cnt;
        } else {
            a = max(0, cnt - 1);
        }
        can += (a / 2 + (a % 2 != 0 ? 1 : 0));
        return can >= n;
    }
};
