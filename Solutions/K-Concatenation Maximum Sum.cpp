class Solution {
public:
    int MaxSubarraySum(const vector<int>& arr) {
        int cur_sum = 0;
        int max_sum = 0;
        for (const int& elem : arr) {
            cur_sum += elem;
            max_sum = max(max_sum, cur_sum);
            if (cur_sum < 0) {
                cur_sum = 0;
            }
        }
        return max_sum;
    }
    
    void FindMaximumPrefixAndSuffix(const vector<int>& arr, int& maximum_prefix_sum, int& maximum_suffix_sum, int& total_sum) {
        int cur_prefix_sum = 0;
        int cur_suffix_sum = 0;
        for (int i = 0, j = int{arr.size()} - 1; i < int{arr.size()}; i++, j--) {
            cur_prefix_sum += arr[i];
            cur_suffix_sum += arr[j];
            total_sum += arr[i];
            maximum_prefix_sum = max(maximum_prefix_sum, cur_prefix_sum);
            maximum_suffix_sum = max(maximum_suffix_sum, cur_suffix_sum);
        }
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int answer = MaxSubarraySum(arr);
        if (k == 1) {
            return answer;
        }
        int maximum_prefix_sum = 0;
        int maximum_suffix_sum = 0;
        int total_sum = 0;
        FindMaximumPrefixAndSuffix(arr, maximum_prefix_sum, maximum_suffix_sum, total_sum);
        const int MOD = 1000000007;
        return max(answer, int((maximum_suffix_sum + maximum_prefix_sum) % MOD + ((long long)(k - 2) * max((long long)total_sum, 0LL) % MOD) % MOD));
    }
};
