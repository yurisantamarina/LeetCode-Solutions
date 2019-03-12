class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nxt = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            if(nxt - 2 >= 0){
                if(nums[nxt - 2] != nums[i]){
                    nums[nxt++] = nums[i];
                }
            }else{
                nxt++;
            }
        }
        return nxt;
    }
};
