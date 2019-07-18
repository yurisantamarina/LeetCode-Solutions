class Solution { 
public:
    char Partition(int idx, int left, const vector<int>& nums, vector<vector<char> >& dp) {
        if (idx == int{nums.size()}) {
            return left == 0 ? 1 : 0;
        }
        if (dp[idx][left] != 2) {
            return dp[idx][left];
        }
        
        char can = Partition(idx + 1, left, nums, dp);
        if (nums[idx] <= left) {
            can |= Partition(idx + 1, left - nums[idx], nums, dp);
        }
        
        return dp[idx][left] = can;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const int& x : nums) {
            sum += x;
        }
        if (sum & 1) {
            return false;
        }
        
        vector<vector<char> > dp(int{nums.size()}, vector<char>(sum / 2 + 1, 2));
        return Partition(0, sum / 2, nums, dp) == 1;
    }
};
