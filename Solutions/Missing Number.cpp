class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_value = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            xor_value ^= (nums[i] ^ i);
        }
        return xor_value;
    }
};
