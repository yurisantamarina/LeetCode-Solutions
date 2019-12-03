class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), lst(nums.size(), -1);
        int lst_index_answer = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    lst[i] = j;
                }
            }
            if (dp[i] > dp[lst_index_answer]) {
                lst_index_answer = i;
            }
        }
        vector<int> answer;
        while (lst_index_answer != -1) {
            answer.push_back(nums[lst_index_answer]);
            lst_index_answer = lst[lst_index_answer];
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
