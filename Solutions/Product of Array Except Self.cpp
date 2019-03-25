class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = (int)nums.size();
        vector<int> prefix(len, 0), suffix(len, 0);
        for (int i = 0, j = len - 1; i < len; i++, j--) {
            prefix[i] = nums[i];
            if (i - 1 >= 0) prefix[i] *= prefix[i - 1];
            suffix[j] = nums[j];
            if (j + 1 < len) suffix[j] *= suffix[j + 1];
        }
        
        vector<int> answer(len);
        long long left = 1, right = 1;
        for (int i = 0; i < len; i++) {
            left = (i - 1 >= 0) ? prefix[i - 1] : 1LL;
            right = (i + 1 < len) ? suffix[i + 1] : 1LL;
            answer[i] = left * right;
        }
        return answer;
    }
};
