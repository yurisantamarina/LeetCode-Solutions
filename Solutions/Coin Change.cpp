class Solution {
public:
    const int kInf = 1000000000;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> min_coins(amount + 1, kInf);
        
        min_coins[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int& coin : coins) {
                if (i - coin >= 0) {
                    min_coins[i] = min(min_coins[i], min_coins[i - coin] + 1);
                }
            }
        }
            
        return min_coins[amount] == kInf ? -1 : min_coins[amount];
    }
};
