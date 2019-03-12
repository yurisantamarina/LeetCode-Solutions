class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i < (int)nums.size(); i++){
            int l = i == 0 ? INT_MIN : nums[i - 1];
            int r = i == (int)nums.size() - 1 ? INT_MIN : nums[i + 1];
            if(l < nums[i] && nums[i] > r)
                return i;
        }
        return 0;
    }
};
