class Solution {
public:
    void solve(int at, int opened, int n, vector<string>& ans, string &s){
        if(at == 2*n){
            if(opened)
                return;
            ans.push_back(s);
            return;
        }
        s += '(';
        solve(at + 1, opened + 1, n, ans, s);
        s.pop_back();
        if(opened){
            s += ')';
            solve(at + 1, opened - 1, n, ans, s);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(0, 0, n, ans, s);
        return ans;
    }
};
