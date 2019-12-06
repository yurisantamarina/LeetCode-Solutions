class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int small = (4 * cheeseSlices) - tomatoSlices;
        if (small % 2 != 0) {
            return {};
        }
        small /= 2;
        int jumbo = cheeseSlices - small;
        if (small < 0 || jumbo < 0) {
            return {};
        }
        return {jumbo, small};
    }
};
