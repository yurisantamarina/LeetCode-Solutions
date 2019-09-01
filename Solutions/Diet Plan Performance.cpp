class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int l = 0, r = k - 1;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += calories[i];
        }
        int ans = 0;
        if (sum < lower) ans--;
        if (sum > upper) ans++;
        while (r < calories.size()) {
            sum -= calories[l];
            l++;
            if (r + 1 >= calories.size()) break;
            r++;
            sum += calories[r];
            if (sum < lower) ans--;
            if (sum > upper) ans++;
        }
        return ans;
    }
};
