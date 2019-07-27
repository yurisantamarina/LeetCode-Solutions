class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (int{timeSeries.size()} == 0) {
            return 0;
        }
        int answer = duration;
        
        for (int i = 1; i < int{timeSeries.size()}; i++) {
             answer += (duration - max((timeSeries[i - 1] + duration - 1) - timeSeries[i] + 1, 0));
        }
        
        return answer;
    }
};
