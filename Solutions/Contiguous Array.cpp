class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstPosition;
        int acc = 0;
        firstPosition[0] = -1;
        int ans = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            acc += (nums[i] ? 1 : -1);
            if(firstPosition.count(acc)){
                ans = max(ans, i - firstPosition[acc]);
            }else{
                firstPosition[acc] = i;
            }
        }
            
        return ans;
    }
};
