class Solution {
public:
    struct interval{
        int s, f, w;

        bool operator < (const struct interval &other) const {
            return f < other.f;
        }
    };
    typedef struct interval Interval;
    static bool compare(Interval &a, int x) {
        return a.f <= x;
    }
    int dp[50010];
    Interval v[50010];
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        Interval x;
        int n = startTime.size();
        for (int i = 0; i < profit.size(); i++) {
            x.s = startTime[i];
            x.f = endTime[i];
            x.w = profit[i];
            v[i + 1] = x;
        }
        sort(v + 1, v + n + 1);
	    dp[0] = 0;
        vector<Interval> V (v, v + n + 1);
        for(int i = 1; i <= n; i++){
            int t = lower_bound(V.begin() + 1, V.begin() + 1 + i, V[i].s, compare) - V.begin() - 1;
            dp[i] = max(dp[i - 1], dp[t] + v[i].w);
        }
        return dp[n];
    }
};
