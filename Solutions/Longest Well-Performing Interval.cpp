class Solution {
public:
    int BinarySearch(int l, int r, int preffix_sum, const vector<int>& min_preffix) {
        int lo = l, hi = r, mid = 0, first_position = 100000;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (min_preffix[mid] >= preffix_sum) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
                first_position = mid;
            }
        }
        return first_position;
    }
    
    int longestWPI(vector<int>& hours) {
        vector<int> min_preffix(int{hours.size()} + 1, 0);
        int preffix_sum = 0;
        int longest_wp_interval = 0;
        for (int i = 0; i < int{hours.size()}; i++) {
            preffix_sum += (hours[i] > 8 ? 1 : -1);
            min_preffix[i + 1] = min(min_preffix[i], preffix_sum);
            longest_wp_interval = max(longest_wp_interval, i - BinarySearch(0, i + 1, preffix_sum, min_preffix) + 1);
        }
        return longest_wp_interval;
    }
    
};
