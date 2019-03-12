class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = (int)nums.size();
        int largest_idx = 0;
        int second_largest = -1;
        for(int i = 1; i < n; i++){
            if(nums[i] >= nums[largest_idx]){
                second_largest = nums[largest_idx];
                largest_idx = i;
            }else if(nums[i] > second_largest){
                second_largest = nums[i];
            }
        }
        return second_largest * 2 <= nums[largest_idx] ? largest_idx : -1;
    }
};
