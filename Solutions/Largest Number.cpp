class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_string;
        for (int& x : nums) {
            nums_string.push_back(to_string(x));
        }
        sort(nums_string.begin(), nums_string.end(), [](const string& a, const string& b) {
           string fst = a + b;
           string snd = b + a;
           return fst > snd;
        });
        string ans = "";
        for (const string& x : nums_string) {
            ans += x;
        }
        int zeros = 0;
        for (char& c : ans) {
            if (c == '0') {
                zeros++;
            }
        }
        if (zeros == int{ans.size()}) {
            ans = "0";
        }
        return ans;
    }
};
