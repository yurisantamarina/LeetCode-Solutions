class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int max_profit[2][2][3];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    max_profit[i][j][k] = -10000000;
                }
            }
        }
        int curr_line = 0;
        max_profit[0][0][0] = 0;
        max_profit[0][1][0] = -prices[0];
        
        for (int i = 1; i < (int)prices.size(); i++) {
            curr_line^=1;
            for (int j = 0; j <= 2; j++) {
                int a = j == 0 ? 0 : max_profit[curr_line^1][1][j - 1] + prices[i];
                int b = max_profit[curr_line^1][0][j];
                max_profit[curr_line][0][j] = max(a, b);
                
                a = max_profit[curr_line^1][1][j];
                b = max_profit[curr_line^1][0][j] - prices[i];
                max_profit[curr_line][1][j] = max(a, b);
            }
        }
        
        return max({max_profit[curr_line][0][0], max_profit[curr_line][0][1], max_profit[curr_line][0][2]});
    }
};
