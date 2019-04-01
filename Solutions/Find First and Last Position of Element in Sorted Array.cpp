class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (l == (int) nums.size() || nums[l] != target) return {-1, -1};
        return {l, r - 1};
    }
};
