class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> f(260, 0);
        int j = 0, ans = 0;
        char c;
        f[s[0]] = 1;
        for(int i = 0; i < (int)s.size(); i++){
            while(j + 1 < (int)s.size() && f[s[j + 1]] == 0){
                f[s[j + 1]]++;
                j++;
            }
            
            f[s[i]]--;
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
    
};
