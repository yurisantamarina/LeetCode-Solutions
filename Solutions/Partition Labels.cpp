class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> lst(26, 0);
        for (int i = 0; i < int{S.size()}; i++) {
            lst[S[i] - 'a'] = i;
        }
        
        vector<int> sizes;
        int curr_len = 1;
        int mx = lst[S[0] - 'a'];
        for (int i = 1; i < int{S.size()}; i++) {
            if (mx < i) {
                mx = lst[S[i] - 'a'];
                sizes.push_back(curr_len);
                curr_len = 1;
            } else {
                mx = max(mx, lst[S[i] - 'a']);
                curr_len++;
            }
        }
        sizes.push_back(curr_len);
        return sizes;
    }
};
