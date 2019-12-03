class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> one_bits(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            one_bits[i] = one_bits[i / 2] + (i & 1);
        }
        return one_bits;
    }
};
