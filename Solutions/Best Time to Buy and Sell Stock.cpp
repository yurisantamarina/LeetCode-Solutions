class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ((int)prices.size() == 0) {
            return 0;
        }
        int max_profit = 0;
        int best_buy = prices[0];
        for (int i = 1; i < (int)prices.size(); i++) {
            max_profit = max(max_profit, prices[i] - best_buy);
            best_buy = min(best_buy, prices[i]);
        }
        
        return max_profit;
    }
};
