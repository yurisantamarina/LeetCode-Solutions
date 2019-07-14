class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int max_profit[2][2];
        
        int curr_line = 0;
        max_profit[0][0] = 0;
        max_profit[0][1] = -prices[0];
        
        for (int i = 1; i < (int)prices.size(); i++) {
            curr_line^=1;
            max_profit[curr_line][0] = max(max_profit[curr_line^1][1] + prices[i], max_profit[curr_line^1][0]);
            max_profit[curr_line][1] = max(max_profit[curr_line^1][1], max_profit[curr_line^1][0] - prices[i]);
        }
        
        return max_profit[curr_line][0];
    }
};
