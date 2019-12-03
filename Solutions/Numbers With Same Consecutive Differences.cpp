class Solution {
public:
    
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        queue<pair<int, int>> numbers;
        for (int digit = 1; digit < 10; digit++) {
            numbers.push({digit, 1});
        }
        vector<int> answer;
        while (!numbers.empty()) {
            int number = numbers.front().first;
            int len = numbers.front().second;
            int last_digit = number % 10;
            numbers.pop();
            if (len == N) {
                answer.push_back(number);
                continue;
            }
            if (last_digit + K < 10) {
                numbers.push({number * 10 + last_digit + K, len + 1});
            }
            if (last_digit - K >= 0 && K != 0) {
                numbers.push({number * 10 + last_digit - K, len + 1});
            }
        }
        return answer;
    }
};
