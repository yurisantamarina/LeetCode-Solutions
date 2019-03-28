class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = (int) height.size() - 1;
        int answer = 0;
        while (l < r) {
            answer = max(answer, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return answer;
    }
};
