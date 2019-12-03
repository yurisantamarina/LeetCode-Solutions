class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() == 1) return 0;
        
        vector<int> dp_orig(arr1.size(), 1000000000);
        vector<vector<int>> dp_change(arr1.size(), vector<int>(arr2.size(), 1000000000));
        sort(arr2.begin(), arr2.end());
        arr2.resize(distance(arr2.begin(), unique(arr2.begin(), arr2.end())));
        
        vector<int> acc_change(arr2.size() + 2);
        dp_orig[0] = 0;
        for (int i = 0; i < arr2.size(); i++) {
            dp_change[0][i] = 1;
            acc_change[i] = dp_change[0][i];
            if (i > 0) {
                acc_change[i] = min(acc_change[i], acc_change[i - 1]);
            }
        }
        int ans = 1000000000;
        
        for (int i = 1; i < arr1.size(); i++) {
            dp_orig[i] = 1000000000;
            if (arr1[i - 1] < arr1[i]) {
                dp_orig[i] = min(dp_orig[i], dp_orig[i - 1]);
            } 
                int pos = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
                pos--;
                if (pos >= 0) {
                    dp_orig[i] = min(dp_orig[i], acc_change[pos]);
                }
            
            if (i == arr1.size() - 1) {
                ans = min(ans, dp_orig[i]);
            }
            for (int j = 0; j < arr2.size(); j++) {
                if (arr1[i - 1] < arr2[j]) {
                    dp_change[i][j] = min(dp_change[i][j], dp_orig[i - 1] + 1);
                }
                if (j > 0) {
                    dp_change[i][j] = min(dp_change[i][j], acc_change[j - 1] + 1);
                }
                
                if (i == arr1.size() - 1) {
                    ans = min(ans, dp_change[i][j]);
                }
            }
            
            for (int j = 0; j < arr2.size(); j++) {
                acc_change[j] = dp_change[i][j];
                if (j > 0) {
                    acc_change[j] = min(acc_change[j], acc_change[j - 1]);
                }
            }
        }
        
        if (ans >= 1000000000) ans = -1;
        return ans;
    }
};
