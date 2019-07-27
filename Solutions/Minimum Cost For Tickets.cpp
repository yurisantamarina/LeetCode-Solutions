class Solution {
public:
    const int kInf = 1000000000;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> min_cost(int{days.size()} + 1, kInf);
        min_cost[0] = 0;
        min_cost[1] = min({costs[0], costs[1], costs[2]});
        
        for (int i = 2; i <= int{days.size()}; i++) {
            for (int j = 1; j <= i; j++) {
                if (days[i - 1] - days[j - 1] + 1 <= 1) {
                    min_cost[i] = min(min_cost[i], min_cost[j - 1] + costs[0]);
                }
                if (days[i - 1] - days[j - 1] + 1 <= 7) {
                    min_cost[i] = min(min_cost[i], min_cost[j - 1] + costs[1]);
                }
                if (days[i - 1] - days[j - 1] + 1 <= 30) {
                    min_cost[i] = min(min_cost[i], min_cost[j - 1] + costs[2]);
                }
            }
        }
        
        return min_cost[int{days.size()}];
    }
};
