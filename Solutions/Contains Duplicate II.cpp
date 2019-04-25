class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> last_position;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (last_position.count(nums[i]) && i - last_position[nums[i]] <= k) {
               return true;
            }
            last_position[nums[i]] = i;
        }
        return false;
    }
};
