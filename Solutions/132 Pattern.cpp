class Solution {
public:

    bool find132pattern(vector<int>& nums) {
        int min_value = INT_MAX;
        vector<int> min_to_the_left(int(nums.size()));
        stack<int> st;
        for (int i = 0; i < int(nums.size()); i++) {
            min_to_the_left[i] = min_value;
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty() && min_to_the_left[st.top()] < nums[st.top()] && min_to_the_left[st.top()] < nums[i]) {
                return true;
            }
            st.push(i);
            min_value = min(min_value, nums[i]);
        }
        return false;
    }
};
