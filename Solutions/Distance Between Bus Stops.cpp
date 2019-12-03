class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) {
            swap(start, destination);
        }
        int n = distance.size();
        if (start == destination) return 0;
        int sum = 0;
        int ans = 1000000000;
        for (int i = start; i < destination; i++) {
            sum += distance[i];
        }
        ans = sum;
        start--;
        if (start == -1) start = n - 1;
        sum = 0;
        for (int i = start; start < destination && i >= 0; i--) {
            sum += distance[i];
        }
        for (int i = n - 1; i >= destination; i--) {
            sum += distance[i];
        }
        ans = min(ans, sum);
        return ans;
    }
};
