class Solution {
public:
    int solve(int house, bool fst, vector<int>& nums, vector<vector<int>>& dp) {
        if (house >= (int)nums.size()) return 0;
        if (dp[house][fst] != -1) return dp[house][fst];
        
        int answer = solve(house + 1, fst, nums, dp);
        if (house == 0) {
            answer = max(answer, nums[house] + solve(house + 2, true, nums, dp));
        } else if (house == (int)nums.size() - 1) {
            if (!fst) {
                answer = max(answer, nums[house] + solve(house + 2, fst, nums, dp));
            }
        } else {
            answer = max(answer, nums[house] + solve(house + 2, fst, nums, dp));
        }
        
        return dp[house][fst] = answer;
    }
    
    int rob(vector<int>& nums) {
        vector<vector<int>> dp((int)nums.size(), vector<int>(2, -1));
        return solve(0, false, nums, dp);
    }
};
